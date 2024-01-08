/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: UART_Core.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_CORE_H_
#define UART_CORE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU.h"
#include "BIT_MATH.h"
#include "UART_CFG.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PARITY_ENABLED   1U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void UART_Init(void);

void UART_InitTx(void);

void UART_SendData (void);

void UART_ReceiveData (void);

void UART_ReceiveByte (void);

uint8 UART_ReceivedData_Status (void);

uint8 UART_ReceivedByte_Status (void);

void UART_EnableReceiving (void);

void UART_DisableReceiving (void);

#endif /* UART_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: UART_Core.h
 *********************************************************************************************************************/




