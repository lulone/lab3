/*
 * button.h
 *
 *  Created on: Oct 29, 2022
 *      Author: HUY
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET
#define NO_BUTTONS		3

extern int button_flag[3];

void getKeyInput();
int isButtonPressed(int index);
int isButtonLongPressed(int index);


#endif /* INC_BUTTON_H_ */
