/*
 * position.c
 *
 *  Created on: Jan 29, 2026
 *      Author: Win11
 */

#include "void_moduli/position.h"
#include "void_moduli/odom.h"
#include <math.h>
const float Kp_w = 1.0f;
const float v_max = 0.3; //m/s
const float a_max = 0.5; //m/s*s
float x_ref = 0.0, y_ref = 0.0, theta_ref = 0.0;
const float eps_dist = 0.05f;   // 5 cm
const float eps_theta = 0.01745f; // 1 stepen
const float w_max = 1.5; //rad/s
const float alpha_max = 3.0f; //rad/s*s ugaono ubrzanje

//Potrebno za sintezu trajektorije
static float s_total; //ukupni put do cilja
static float s1, s2, s3; //tri puta, jedan prilikom ubrzavanja, jedan konstantna brzina, i jedan prilikom usporavanja, to je trapezni profil brzine

static float th_total; //ukupni ugao
static float th1, th2, th3;

Motion_state_t current_state = IDLE;

void set_ref_position(float x_goal, float y_goal, float theta_goal) {
	if (current_state == IDLE) {
		x_ref = x_goal;
		y_ref = y_goal;
		theta_ref = theta_goal;

		float dx = x_ref - x;
		float dy = y_ref - y;

		s_total = sqrtf(dx * dx + dy * dy);

		//Sad izracunamo s1, s2 i s3 na osnovu svega
		//mozemo s1, jer je v0 na pocetku 0
		s1 = (v_max * v_max) / (2 * a_max);
		s3 = s1;
		s2 = s_total - 2 * s1;
		//Ako je put bas kratak, trougaoni profil, nikad se ne dostize vmax
		if (s2<0)
		{
			s1 = s_total / 2;
			s2 = 0;
			s3 = s1;
		}
		current_state = HEADING_POSE;
	}


}

static float trajectory_v(float s) {
	if (s < s1)
		return sqrtf(2.0f * a_max * s);
	else if(s > s1 && s <= (s1 + s2))
	{
				return v_max;
	}
	else if (s > (s1 + s2) && s <= s_total)
	{
		return sqrtf(v_max * v_max - 2 * a_max * (s - s1 - s2));
	}
	else
		return 0.0f;
}

static float trajectory_w(float th) {
	if (th < th1)
	{
		return sqrtf(2.0f * alpha_max * th);
	}

	else if (th > th1 && th < (th1 + th2))
	{
		return w_max;
	}

	else if (th > (th1 + th2) && th <= th_total)
	{
		return sqrtf((w_max * w_max) - 2 * alpha_max * (th - th1 - th2));
	} else
	{
		return 0.0f;
	}

}

void position_loop() {
	float v_ref = 0;
	float w_ref = 0;

	float dx = x_ref - x; //x zeljeno minus trenutno x, dobijemo x koje treba da predjemo
	float dy = y_ref - y;

	float distance_error = sqrtf(dx * dx + dy * dy); //pitagorina teorema
	float heading_angle = atan2f(dy, dx);

	float heading_error = normalize_rad_angle(heading_angle - theta); //imamo 3 faze, pa zato imamo i tri greske, prva faza je rotacija ka zeljenom pravcu, druga faza je translaciji, treca faza je rotacija ka cilju
	float theta_error = normalize_rad_angle(theta_ref - theta);

	float th=0.0;
	float w_ref_done=0.0;

	switch (current_state) {
	case HEADING_POSE:
		v_ref = 0;
		th_total = fabsf(heading_angle - theta); //ukupan ugao za koji robot treba da se okrene
		th1 = (w_max * w_max) / (2.0f * alpha_max);
		th3 = th1;
		th2 = th_total - 2.0f * th1;

		if (th2<0.0f)
		{
			th1 = th_total / 2.0f;
			th2 = 0.0f;
			th3 = th1;
		}

		 th = th_total - fabsf(heading_error); //koliko se zapravo robot okrenuo do sada
		 w_ref_done = trajectory_w(th);

		w_ref = copysignf(w_ref_done, heading_error); //ovo znaci da uzme vrednost w, ali znak heading_error

		if (fabsf(heading_error) < eps_theta && fabsf(w) < 0.01f) {
			current_state = TRANSLATE_TO_GOAL;
		}
		break;
	case TRANSLATE_TO_GOAL:
		float s = s_total - distance_error; //koliko smo presli do sada ka cilju

		v_ref = trajectory_v(s);

		// P-korekcija pravca (BEZ sinteze)
		w_ref = Kp_w * heading_error;

		if (distance_error < eps_dist && fabsf(v) < 0.01f && fabsf(w) < 0.01f) {

			current_state = ROTATE_TO_GOAL;
		}
		break;

	case ROTATE_TO_GOAL:
		v_ref = 0;
		// sinteza rotacije prema KONACNOM UGLU
		th_total = fabsf(theta_error);

		th1 = (w_max * w_max) / (2.0f * alpha_max);
		th3 = th1;
		th2 = th_total - 2.0f  * th1;

		if (th2<0) {
			th1 = th_total / 2.0f;
			th2 = 0.0f;
			th3 = th1;
		}
		 th = th_total - fabsf(theta_error); //znaci koliko se robot okrenuo do sada
		 w_ref_done = trajectory_w(th);
		w_ref = copysignf(w_ref_done, theta_error);

		if (fabsf(theta_error) < eps_theta && fabsf(w) <= 0.01) {
			current_state = GOAL_POSITION;
			w_ref = 0.0;
			v_ref = 0.0;
		}
		break;

	case GOAL_POSITION:
		v_ref = 0.0;
		w_ref = 0.0;
		break;
	}
}


