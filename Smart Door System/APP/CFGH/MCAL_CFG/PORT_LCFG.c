/*
 * PORT_LCFG.c
 *
 * Created: 9/16/2023 12:15:32 PM
 *  Author: alima
 */ 

#include "PORT_LCFG.h"

PIN_PARAMETERS PORT_Initialization[DEFINED_PINS]=
{
	
    { PORTA_PIN1   ,  PIN_DIR_OUTPUT  }, //LCD
    { PORTA_PIN2   ,  PIN_DIR_OUTPUT  }, //LCD
    { PORTA_PIN3   ,  PIN_DIR_OUTPUT  }, //LCD
    { PORTA_PIN4   ,  PIN_DIR_OUTPUT  }, //LCD
    { PORTA_PIN5   ,  PIN_DIR_OUTPUT  }, //LCD
    { PORTA_PIN6   ,  PIN_DIR_OUTPUT  }, //LCD

	{ PORTC_PIN0   ,  PIN_DIR_OUTPUT  },  //SCL
	{ PORTC_PIN1   ,  PIN_DIR_OUTPUT  },  //SDA
		
	{ PORTD_PIN0   ,  PIN_DIR_INPUT  },   //RX
	{ PORTD_PIN1   ,  PIN_DIR_OUTPUT },   //TX
	
	{ PORTD_PIN5  ,  PIN_DIR_OUTPUT },   //PWM1
	
	{ PORTC_PIN2   ,  PIN_DIR_OUTPUT  }, //Blue led
	{ PORTC_PIN5   ,  PIN_DIR_OUTPUT  }  //Buzzer					
};  //This is Array of Structs