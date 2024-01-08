/*
 * LED_Core.h
 *
 * Created: 9/15/2023 10:02:59 AM
 *  Author: alima
 */ 


#ifndef LED_CORE_H_
#define LED_CORE_H_

#include "DIO_Core.h"

#define  RED_LED     0U
#define  GREEN_LED   1U
#define  BLUE_LED    2U

#define  SELECTED_LED   BLUE_LED

void LED_Init (void);
void LED_ON   (void);
void LED_OFF  (void);
void LED_TGL  (void);


#endif /* LED_CORE_H_ */