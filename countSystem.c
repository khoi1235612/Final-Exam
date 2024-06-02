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

	if (is_button_held(1) == 1) {
		wrapAroundCounter(n++);
	}

	if (is_button_held(2) == 1) {
		wrapAroundCounter(n--);
	}

	if (timer1_flag == 1) {
			if (is_button_pressed(0) == 0 && is_button_pressed(1) == 0 && is_button_pressed(2) == 0) {
				n--;
				if (n < 0) n=0;
				setTimer1(1000);
			}
	}

	if (timer2_flag == 1){
		display7SEG(n);
		setTimer2(1);
	}

}


