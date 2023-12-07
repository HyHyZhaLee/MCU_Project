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



void trafficDisplay1(uint8_t input);
void trafficDisplay2(uint8_t input);
void pedestrianDispay(uint8_t input);



#endif /* INC_HARDWARE_H_ */
