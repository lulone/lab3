/*
 * input_processing.c
 *
 *  Created on: Nov 3, 2022
 *      Author: HUY
 */
#include "button.h"
#include "input_processing.h"

int autoCount = 8;
int count = 0;
int t_count = 0;
int t_count1 = 0;


void fsm_for_input_processing1(void){ //MODE1
	switch(mode){
		case MODE1:
			switch(status){
				case INIT:
					HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
					t_count = red_count / 100;
					status = RED;
					setTimer1(100);
					break;
				case RED:
					HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
					if(timer2_flag == 1){
						update7SEG(t_count);
						setTimer2(autoCount);
					}
					if(timer1_flag == 1){
						t_count--;
						if(t_count == 0){
							status = GREEN;
							t_count = green_count / 100;
						}
						setTimer1(100);
					}
					break;
				case YELLOW:
					HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
					if(timer2_flag == 1){
						update7SEG(t_count);
						setTimer2(autoCount);
					}
					if(timer1_flag == 1){
						t_count--;
						update7SEG(t_count);
						if(t_count == 0){
							status = RED;
							t_count = red_count / 100;
						}
						setTimer1(100);
					}
					break;
				case GREEN:
					HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
					if(timer2_flag == 1){
						update7SEG(t_count);
						setTimer2(autoCount);
					}
					if(timer1_flag == 1){
						t_count--;
						update7SEG(t_count);
						if(t_count == 0){
							status = YELLOW;
							t_count = yellow_count / 100;
						}
						setTimer1(100);
					}
					break;
			}

			switch(status1){
				case INIT:
					HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);
					t_count1 = green_count / 100;
					status1 = GREEN;
					setTimer3(100);
					break;
				case RED:
					HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);
					if(timer4_flag == 1){
						update7SEGb(t_count1);
						setTimer4(autoCount);
					}
					if(timer3_flag == 1){
						t_count1--;
						if(t_count1 == 0){
							status1 = GREEN;
							t_count1 = green_count / 100;
						}
						setTimer3(100);
					}
					break;
				case YELLOW:
					HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);
					if(timer4_flag == 1){
						update7SEGb(t_count1);
						setTimer4(autoCount);
					}
					if(timer3_flag == 1){
						t_count1--;
						update7SEG(t_count1);
						if(t_count1 == 0){
							status1 = RED;
							t_count1 = red_count / 100;
						}
						setTimer3(100);
					}
					break;
				case GREEN:
					HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_RESET);
					if(timer4_flag == 1){
						update7SEGb(t_count1);
						setTimer4(autoCount);
					}
					if(timer3_flag == 1){
						t_count1--;
						update7SEG(t_count1);
						if(t_count1 == 0){
							status1 = YELLOW;
							t_count1 = yellow_count / 100;
						}
						setTimer3(100);
					}
					break;
			}
			if(isButtonPressed(0)){
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);

				mode = MODE2;
				setTimer1(1);
				setTimer2(1);
				setTimer3(1);
				setTimer4(1);
			}
			break;
		case MODE2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG(2);

			if(timer1_flag == 1){
				update7SEG(count);
				setTimer1(autoCount);
			}

			if(timer2_flag == 1){
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				HAL_GPIO_TogglePin(LED_REDb_GPIO_Port, LED_REDb_Pin);
				HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);
				setTimer2(50);
			}
			if(isButtonPressed(1)){
				count++;
				if (count > 99)
					count = 0;
			}
			else if(isButtonPressed(2)){
				red_count = count * 100;
			}
			else if(isButtonPressed(0)){
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);

				mode = MODE3;
				count = 0;
				setTimer1(1);
				setTimer2(1);
			}
			break;
		case MODE3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG(3);
			if(timer1_flag == 1){
				update7SEG(count);
				setTimer1(autoCount);
			}

			if(timer2_flag == 1){
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
				HAL_GPIO_TogglePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin);
				HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);
				setTimer2(50);
			}

			if(isButtonPressed(1)){
				count++;
				if (count > 99)
					count = 0;
			}
			if(isButtonPressed(2)){
				yellow_count = count * 100;
			}
			if(isButtonPressed(0)){
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);

				mode = MODE4;
				count = 0;
				setTimer1(1);
				setTimer2(1);
			}
			break;
		case MODE4:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG(4);
			if(timer1_flag == 1){
				update7SEG(count);
				setTimer1(autoCount);
			}

			if(timer2_flag == 1){
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);

				HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
				HAL_GPIO_TogglePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin);
				setTimer2(50);
			}

			if(isButtonPressed(1)){
				count++;
				if (count > 99)
					count = 0;
			}
			if(isButtonPressed(2)){
				green_count = count * 100;
			}
			if(isButtonPressed(0)){
				/*HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED_REDb_GPIO_Port, LED_REDb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOWb_GPIO_Port, LED_YELLOWb_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREENb_GPIO_Port, LED_GREENb_Pin, GPIO_PIN_SET);*/

				mode = MODE1;
				count = 0;
				status = INIT;
				status1 = INIT;
				//clear7SEG();
				setTimer1(1);
				setTimer2(1);
			}
			break;
		default:
			break;
	}
}
