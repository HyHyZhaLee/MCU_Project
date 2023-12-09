/*
 * hardware_unit_test.h
 *
 *  Created on: Dec 7, 2023
 *      Author: Admin
 */

#ifndef INC_HARDWARE_H_
#define INC_HARDWARE_H_

#include "global.h"

#ifndef OFF
#define OFF	0
#endif


#ifndef RED
#define RED	1
#endif

#ifndef YELLOW
#define YELLOW	2
#endif

#ifndef GREEN
#define GREEN	3
#endif


// LED DISPLAY
void trafficDisplay1(uint8_t input); 							//DISPLAY TRAFFIC1 PORT D2-D3
void trafficDisplay2(uint8_t input); 							//DISPLAY TRAFFIC2 PORT D4-D5
void pedestrianDispay(uint8_t input); 							//DISPLAY PEDESTRIAN PORT D6-D7
void trafficToggle(uint8_t input); 								//TOGGLE TRAFFIC1 PORT D2-D3 + TRAFFIC2 PORT D4-D5
/* FOR BUTTON0 = PORT A0 A1
 * FOR BUTTON1 = PORT A1 A2
 * FOR BUTTON2 = PORT A2 A3
 * FOR BUTTON3 = PORT A3 A4
 */
unsigned char is_button_pressed ( unsigned char index ) ; 		//CHECK BUTTON PRESS
unsigned char is_button_long_pressed( unsigned char index ) ; 	//CHECK BUTTON LONG PRESS

//BUZZER
void BuzzerOn(); //TURN ON BUZZER
void BuzzerOff();//TURN OFF BUZZER

/*
 * FOR RUNNING DEBUG HARDWARE
 * UNCOMMENT THESE LINE:
 */
//#define __TEST_BUTTON
//#define __TEST_TRAFFIC
//#define __TEST_BUZZER
//#define __TEST_TOGGLE

void runAutoDebug(); //RUNNING DEBUG
#endif /* INC_HARDWARE_H_ */
