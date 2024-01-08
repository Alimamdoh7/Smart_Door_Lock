/*
 * MCU.h
 *
 * Created: 9/15/2023 10:06:24 AM
 *  Author: alima
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "STD.h"


/****************** GPIO Registers **************/
#define PINA   *(volatile uint8*)(0x39)
#define DDRA   *(volatile uint8*)(0x3A)
#define PORTA  *(volatile uint8*)(0x3B)

#define PINB   *(volatile uint8*)(0x36)
#define DDRB   *(volatile uint8*)(0x37)
#define PORTB  *(volatile uint8*)(0x38)

#define PINC   *(volatile uint8*)(0x33)
#define DDRC   *(volatile uint8*)(0x34)
#define PORTC  *(volatile uint8*)(0x35)

#define PIND   *(volatile uint8*)(0x30)
#define DDRD   *(volatile uint8*)(0x31)
#define PORTD  *(volatile uint8*)(0x32)
/************************************************/

/************************************** EXTERNAL INT Registers ******************************/
#define SREG   (*(volatile uint8*)(0X5F))
#define GICR   (*(volatile uint8*)(0X5B))
#define MCUCR  (*(volatile uint8*)(0X55))
#define MCUCSR (*(volatile uint8*)(0X54))


/*************************************** ADC Registers ************************************************/

/*************************************** Timer0 ************************************************/

/**************************************Timer1***********************************************************/
#define TCCR1A              (*(volatile uint8* )(0x4F))
/*****************************************************************************************************/

/**************************************WDT***********************************************************/

#define WDTCR    (*(volatile uint8*)(0X41))

/**************************************UART***********************************************************/
#define UBRRH   (*((volatile uint8*)0x40))

/**************************************SPI***********************************************************/

typedef struct
{
	uint8 SPR : 2;
	uint8 CPHA: 1;
	uint8 CPOL: 1;
	uint8 MSTR: 1;
	uint8 DORD: 1;
	uint8 SPE : 1;
	uint8 SPIE: 1;
}SPCR_BITS;

typedef struct  
{
	SPCR_BITS SPCR;
	uint8     SPSR;
	uint8     SPDR;
}SPI_Type;


#define SPI_REGS ((volatile SPI_Type*)(0X2D))
/****************************************************************************************************/

/**************************************I2C***********************************************************/
#define TWCR    (*((volatile uint8*)0x56))
/****************************************************************************************************/

#endif /* MCU_H_ */