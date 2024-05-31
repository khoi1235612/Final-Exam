/*
 * countSystem.c
 *
 *  Created on: May 28, 2024
 *      Author: Windows 10 TIMT
 */
#include "countSystem.h"
void wrapAroundCounter(){
	if (n > 9) n=0;
	if (n < 0) n=9;
}
int n = 0;
void countSystem(){
	if (is_button_pressed(0) == 1){
		n = 0;
	}

	if (is_button_pressed(1) == 1){
		wrapAroundCounter(n++);
	}

	if (is_button_pressed(2) == 1){
		wrapAroundCounter(n--);
	}

	if (timer0_flag == 1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer0(100);
	}
	if (timer1_flag == 1){
		display7SEG(n);
		setTimer1(1);
	}

}


