/*
 * global.h
 *
 *  Created on: Nov 3, 2022
 *      Author: HUY
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"
#include "software_timer.h"
#include "output_display.h"
#include "7SEG_display.h"

#define	INIT	0
#define RED		1
#define YELLOW	2
#define	GREEN	3
#define MODE1	4
#define	MODE2	5
#define MODE3	6
#define MODE4	7

extern int mode;
extern int status;
extern int status1;
extern int red_count;
extern int green_count;
extern int yellow_count;

#endif /* INC_GLOBAL_H_ */
