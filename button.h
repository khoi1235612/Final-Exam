/*
 * button.h
 *
 *  Created on: May 28, 2024
 *      Author: Windows 10 TIMT
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET


void getKeyInput();
int is_button_pressed ( int index );
int is_button_held (int index);


#endif /* INC_BUTTON_H_ */
