/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EEPROM_Core.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef EEPROM_CORE_H_
#define EEPROM_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "I2C_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define   EEPROM_ADDRESS     0X50
#define   Read_Data_Size     4U
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
void EEPROM_WriteByte (uint8 Data , uint8 EEPROM_Address , uint8 Byte_Address);
void EEPROM_WriteMultipleBytes (uint8 *Data , uint8 Data_Size , uint8 EEPROM_Address , uint8 Byte_Address);
uint8 EEPROM_ReadByte (uint8 EEPROM_Address , uint8 Byte_Address);
uint8*  EEPROM_ReadMultipleBytes ( uint8 EEPROM_Address , uint8 Byte_Address);
#endif /* EEPROM_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: EEPROM_Core.h
 *********************************************************************************************************************/








