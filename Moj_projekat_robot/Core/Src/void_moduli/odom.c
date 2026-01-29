/*
 * odom.c
 *
 *  Created on: Jan 28, 2026
 *      Author: Win11
 */

#include "void_moduli/odom.h"
#include "timer.h"
#include <math.h>
#include "void_moduli/pwm.h"

const float C_INC2RAD = 0.00076699039; 	// [rad/inc]
const float radius_tocka = 0.0775 / 2; 	// [m]
const float rastojanje_tockova = 0.255; // [m]
volatile float x = 0, y = 0, theta = 0, v_l = 0, v_r = 0, w = 0, v = 0;

void odom_loop() {
	v_r = enc1_get_delta_inc() * C_INC2RAD * radius_tocka / DT;
	v_l = enc2_get_delta_inc() * C_INC2RAD * radius_tocka / DT;
	v = (v_r + v_l) / 2;
	w = (v_r - v_l) / rastojanje_tockova;
	v_r_measured = v + w * HALF_SEPARATION_WHEEL;
	v_l_measured = v - w * HALF_SEPARATION_WHEEL;

	x += v * DT * cosf(theta + w * DT / 2.0);
	y += v * DT * sinf(theta + w * DT / 2.0);
	theta += w * DT;
	theta = normalize_rad_angle(theta);

}

float normalize_rad_angle(float angle) //ovo je samo ogranicenje da se ugao nalzi izmedju minu pi i pi
{
	if (angle > M_PI) {
		return angle - 2 * M_PI;
	}
	if (angle < -M_PI) {
		return angle + 2 * M_PI;
	}

	return angle;
}
