/*
 * position.h
 *
 *  Created on: Jan 29, 2026
 *      Author: Win11
 */

#ifndef INC_VOID_MODULI_POSITION_H_
#define INC_VOID_MODULI_POSITION_H_



#endif /* INC_VOID_MODULI_POSITION_H_ */

typedef enum
{
	IDLE,
	HEADING_POSE,
	TRANSLATE_TO_GOAL,
	ROTATE_TO_GOAL,
	GOAL_POSITION
}Motion_state_t;

//Prototipovi funkcija
void set_ref_position(float x_goal, float y_goal, float theta_goal);
void position_loop();
