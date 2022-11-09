/*
 * 7SEG_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: HUY
 */
#include "7SEG_display.h"

int led_buffer[4] = {0};
int i = 0;
int j = 0;

void display7SEG(int num){
	switch(num){
		case 0:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
			break;
		}
		case 1:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
			break;
		}
		case 2:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		case 3:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		case 4:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		case 5:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		case 6:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		case 7:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
			break;
		}
		case 8:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		case 9:{
			HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
			break;
		}
		default:
			break;
	}
}

void display7SEGb(int num){
	switch(num){
		case 0:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_SET);
			break;
		}
		case 1:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_SET);
			break;
		}
		case 2:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		case 3:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		case 4:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		case 5:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		case 6:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		case 7:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_SET);
			break;
		}
		case 8:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		case 9:{
			HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_RESET);
			break;
		}
		default:
			break;
	}
}

void updateLedBuffer(int val){
	led_buffer[0] = val / 10;
	led_buffer[1] = val % 10;
}

void update7SEG(int val){
	switch (i) {
		case 0:
		{
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			updateLedBuffer(val);
			display7SEGb(led_buffer[0]);
			i = 1;
			break;
		}
		case 1:
		{
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			display7SEGb(led_buffer[1]);
			i = 0;
			break;
		}
		default :
			break ;
	}
}

void updateLedBuffer1(int val){
	led_buffer[2] = val / 10;
	led_buffer[3] = val % 10;
}

void update7SEGb(int val){
	switch (j) {
		case 0:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			updateLedBuffer1(val);
			display7SEG(led_buffer[2]);
			j = 1;
			break;
		}
		case 1:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG(led_buffer[3]);
			j = 0;
			break;
		}
		default :
			break ;
	}
}

void clear7SEG(void){
	HAL_GPIO_WritePin (SEG0b_GPIO_Port, SEG0b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG1b_GPIO_Port, SEG1b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG2b_GPIO_Port, SEG2b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG3b_GPIO_Port, SEG3b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG4b_GPIO_Port, SEG4b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG5b_GPIO_Port, SEG5b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG6b_GPIO_Port, SEG6b_Pin, GPIO_PIN_SET);

	/*HAL_GPIO_WritePin (SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);*/
}
