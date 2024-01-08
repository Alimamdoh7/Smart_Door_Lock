/*
 * LED_Core.c
 *
 * Created: 9/15/2023 10:02:22 AM
 *  Author: alima
 */ 

#include "LED_Core.h"

void LED_Init (void)
{
	#if (SELECTED_LED == RED_LED)
	SET_BIT(DDRC,0);
	#elif (SELECTED_LED == GREEN_LED)
	SET_BIT(DDRC,1);
	#elif (SELECTED_LED == BLUE_LED)
	SET_BIT(DDRC,2);
	#endif //#if (SELECTED_LED == RED_LED)
	
}
void LED_ON (void)
{
	#if (SELECTED_LED == RED_LED)
	DIO_WriteChannel(PORTC_PIN0 , PIN_HIGH);
	#elif (SELECTED_LED == GREEN_LED)
	DIO_WriteChannel(PORTC_PIN1 , PIN_HIGH);
	#elif (SELECTED_LED == BLUE_LED)
	DIO_WriteChannel(PORTC_PIN2 , PIN_HIGH);
	#endif //#if (SELECTED_LED == RED_LED)
}
void LED_OFF (void)
{
	#if (SELECTED_LED == RED_LED)
	DIO_WriteChannel(PORTC_PIN0 , PIN_LOW);
	#elif (SELECTED_LED == GREEN_LED) 
	DIO_WriteChannel(PORTC_PIN1 , PIN_LOW);
	#elif (SELECTED_LED == BLUE_LED)  
	DIO_WriteChannel(PORTC_PIN2 , PIN_LOW);
	#endif //#if (SELECTED_LED == RED_LED)
}
void LED_TGL (void)
{
	#if (SELECTED_LED == RED_LED)
	DIO_FlipChannel(PORTC_PIN0);
	#elif (SELECTED_LED == GREEN_LED)
	DIO_FlipChannel(PORTC_PIN1);
	#elif (SELECTED_LED == BLUE_LED)
	DIO_FlipChannel(PORTC_PIN2);
	#endif //#if (SELECTED_LED == RED_LED)
}