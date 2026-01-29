/*
 * user_main.c
 *
 *  Created on: Jan 28, 2026
 *      Author: Win11
 */

#include "void_moduli/enc.h"
#include "stm32f4xx_hal.h"
#include "void_moduli/pwm.h"
#include "void_moduli/position.h"
#include "void_moduli/ax12.h"

void user_main() {

	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);

	encoders_init();

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

	HAL_TIM_Base_Start_IT(&htim1); //Pokreni interrupt tajmer

//	set_ref_velocity(-0.2, 0);
    set_ref_position(0.5, 0.5, 0);



		ax12_rack_down();
		HAL_Delay(1000);
		ax12_rack_up();
		HAL_Delay(1000);
}

