/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: HUY
 */

#include "button.h"


int KeyReg0[NO_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NO_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NO_BUTTONS] = {NORMAL_STATE};

int KeyReg3[NO_BUTTONS] = {NORMAL_STATE};// trang thai on dinh truoc do
int TimerForKeyPress= 300;

int button_flag[NO_BUTTONS] = {0};
int button_long_flag[NO_BUTTONS] = {0};

int isButtonPressed(int index){
	if (button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}else
		return 0;
}

int isButtonLongPressed(int index){
	if (button_long_flag[index] == 1){
		button_long_flag[index] = 0;
		button_flag[index] = 0;
		return 1;
	}else
		return 0;
}

void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput(){
	int i;
	for (i = 0; i < NO_BUTTONS; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if (i == 0)
			KeyReg2[i] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
		if (i == 1)
			KeyReg2[i] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
		if (i == 2)
			KeyReg2[i] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){ //tin hieu moi khac voi tin hieu on dinh truoc do -> nhan tha
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					if(button_long_flag == 0)
						TimerForKeyPress = 300;
				}else{
					button_long_flag[i] = 0;
					TimerForKeyPress = 300;
				}
			}else{ //nhan de
				TimerForKeyPress--;
				if(TimerForKeyPress== 0){
					button_long_flag[i] = 1;
					TimerForKeyPress = 50;
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
