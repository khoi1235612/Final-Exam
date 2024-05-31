/*
 * button.c
 *
 *  Created on: May 28, 2024
 *      Author: Windows 10 TIMT
 */
#include "button.h"
#define TIME_FOR_PRESS_KEY 200
#define NUM_BUTTONS 3

int KeyReg0[NUM_BUTTONS] = { SET };
int KeyReg1[NUM_BUTTONS] = { SET };
int KeyReg2[NUM_BUTTONS] = { SET };
int KeyReg3[NUM_BUTTONS] = { SET };

int TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
int button_flag[NUM_BUTTONS] = { RESET };

int button_inc_press_time = 0;
int button_dec_press_time = 0;
int counter = 0;

int is_button_pressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	//TODO
	button_flag[index] = 1;

}

void getKeyInput() {
	for (int i = 0; i < 3; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		switch (i) {
		case 0:
			KeyReg0[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
			break;
		case 1:
			KeyReg0[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
			break;
		case 2:
			KeyReg0[i] = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
			break;
		default:
			break;
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg2[i] != KeyReg3[i]) {
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg3[i] == PRESSED_STATE) {
					subKeyProcess(i);
				}
			} else {
				TimeOutForKeyPress--;

				if (TimeOutForKeyPress == 0) {
					if (KeyReg2[i] == PRESSED_STATE) {
						TimeOutForKeyPress = TIME_FOR_PRESS_KEY;


					}
				}
				}

			}

	}
}

void keyHold() {
	if (HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin) == GPIO_PIN_RESET)
	    {
	      if (HAL_GetTick() - button_inc_press_time > 3000)
	      {
	        // Button INC is pressed for more than 3 seconds
	        counter++;
	        if (counter > 9)
	        {
	          counter = 0;
	        }
	        display7SEG(counter);
	      }
	      else if (HAL_GetTick() - button_inc_press_time > 1000)
	      {
	        // Button INC is pressed for more than 1 second but less than 3 seconds
	        counter++;
	        if (counter > 9)
	        {
	          counter = 0;
	        }
	        display7SEG(counter);
	      }
	    }
	    else
	    {
	      // Button INC is released
	      button_inc_press_time = 0;
	    }

	    if (HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin) == GPIO_PIN_RESET)
	    {
	      if (HAL_GetTick() - button_dec_press_time > 3000)
	      {
	        // Button DEC is pressed for more than 3 seconds
	        counter--;
	        if (counter < 0)
	        {
	          counter = 9;
	        }
	        display7SEG(counter);
	      }
	      else if (HAL_GetTick() - button_dec_press_time > 1000)
	      {
	        // Button DEC is pressed for more than 1 second but less than 3 seconds
	        counter--;
	        if (counter < 0)
	        {
	          counter = 9;
	        }
	        display7SEG(counter);
	      }
	    }
	    else
	    {
	      // Button DEC is released
	      button_dec_press_time = 0;
	    }
}



