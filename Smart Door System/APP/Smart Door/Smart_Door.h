
#ifndef SMART_DOOR_H_
#define SMART_DOOR_H_

#include "PORT_Core.h"
#include "LCD_Core.h"
#include "DIO_Core.h"
#include "IRQH_Core.h"
#include "GPT_Core.h"
#include "PWM_Core.h"
#include "UART_Core.h"
#include "EEPROM_Core.h"
#include "Buzzer_Core.h"
#include "LED_Core.h"
#include "ServoMotor_Core.h"
#include "I2C_Core.h"

#define PASSWORD_ADRESS        0X00
#define PASSWORD_FLAG_ADRESS   0X05
#define PASSWORD_SIZE          4U
#define Door_Custom_Character  0

extern uint8 UART_RECEIVED_BYTE;

void App (void);
void Project_Init (void);
void Drivers_Init (void);
void Welcome_Message (void);
void CheckIfPasswordIsStoredInEEPROM (void);
void SetNewPinForFirstTimeOnly (void);
void Write_Password_In_EEPROM (void);
void Right_Password_Sequence (void);
void Wrong_Password_Sequence(void);
void PIN_Entry_Sequence(void);
void Change_PIN_Sequence(void);
void New_PIN_Entry_Sequence(void);
void Wrong_Password_Sequence_For_Changing_Pin (void);

#endif /* SMART_DOOR_H_ */