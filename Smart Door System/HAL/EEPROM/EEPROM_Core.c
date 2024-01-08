/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file EEPROM_Core.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EEPROM_Core.h"
#define F_CPU 16000000U
#include <util/delay.h>
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void EEPROM_WriteByte (uint8 Data , uint8 EEPROM_Address , uint8 Byte_Address)
{
	I2C_StartCondition();
	I2C_SlaveAddress_WriteOperation(EEPROM_Address);
	I2C_WriteByte(Byte_Address);
	I2C_WriteByte(Data);
	I2C_StopCondition();
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

uint8 EEPROM_ReadByte (uint8 EEPROM_Address , uint8 Byte_Address)
{
	uint8 Data=0;
	I2C_StartCondition();
	I2C_SlaveAddress_WriteOperation(EEPROM_Address);
	I2C_WriteByte(Byte_Address);
	I2C_RepeatedStart();
	I2C_SlaveAddress_ReadOperation(EEPROM_Address);
	Data = I2C_ReadByte();
	I2C_StopCondition();
	return Data;
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void EEPROM_WriteMultipleBytes (uint8 *Data , uint8 Data_Size , uint8 EEPROM_Address , uint8 Byte_Address)
{
	uint8 Data_Cntr=0;
	I2C_StartCondition();
	I2C_SlaveAddress_WriteOperation(EEPROM_Address);
	I2C_WriteByte(Byte_Address);
	while (Data_Cntr < Data_Size)
	{
		I2C_WriteByte(Data[Data_Cntr]);
		Data_Cntr++;
	}
	I2C_StopCondition();
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint8* EEPROM_ReadMultipleBytes (uint8 EEPROM_Address , uint8 Byte_Address)
{
	uint8 Data_Cntr=0;
	static uint8 Data[Read_Data_Size]={0};
	I2C_StartCondition();
	I2C_SlaveAddress_WriteOperation(EEPROM_Address);
	I2C_WriteByte(Byte_Address);
	I2C_RepeatedStart();
	I2C_SlaveAddress_ReadOperation(EEPROM_Address);
	while (Data_Cntr < Read_Data_Size)
	{
		Data[Data_Cntr]=I2C_ReadByte();
		Data_Cntr++;
	}
	I2C_StopCondition();
	return Data;
}
/**********************************************************************************************************************
 *  END OF FILE: EEPROM_Core.c
 *********************************************************************************************************************/
