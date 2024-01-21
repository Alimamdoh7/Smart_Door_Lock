/*
 * Smart_Door.c
 *
 * Created: 1/1/2024 11:44:55 AM
 *  Author: Ali Mamdoh
 */ 
#include "Smart_Door.h"

uint8 UART_Received_Data[PASSWORD_SIZE];
uint8 Pass_Flag=0;
uint8 Password[PASSWORD_SIZE]={'0','0','0','0'};
uint8 Wrong_Pass_Cntr=0;
uint8 Return_Byte =0;
uint8 Return_Value =0;
uint8 * Pass_Ptr = NULL;


void App (void)
{
	Return_Byte = UART_ReceivedByte_Status();
	if (Return_Byte == 1)
	{
		if (UART_RECEIVED_BYTE == '1')
		{
			Change_PIN_Sequence();
		}
		else  if (UART_RECEIVED_BYTE == '2')
		{
			PIN_Entry_Sequence();
		}
	}
}

void Drivers_Init (void)
{
	PORT_Init();
	LCD_Init();
	IRQH_SetGlobalInterrupts(INTERRUPT_ENABLE);
	IRQH_SetCallBackUART(UART_ReceiveByte);
	UART_Init();
	I2C_MasterInit();
	GPT_Init();
	ServoMotor_Init();
	ServoMotor_Home();
}

void Project_Init (void)
{
	Drivers_Init();
	LCD_WriteCustomCharacter();
	Welcome_Message();
	CheckIfPasswordIsStoredInEEPROM();
}

void Welcome_Message (void)
{
	LCD_GoTo(0,0);
	LCD_WriteString("Smart Door");
	LCD_GoTo(0,11);
	LCD_WriteChar(Door_Custom_Character); 
	LCD_GoTo(1,0);
	LCD_WriteString("Project");
	_delay_ms(1500);
	LCD_Clear();
	
	LCD_GoTo(0,0);
	LCD_WriteString("You Have");
	LCD_GoTo(1,0);
	LCD_WriteString("Three Trials");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_GoTo(0,0);
	LCD_WriteString("Made By :");
	LCD_GoTo(1,0);
	LCD_WriteString("Ali Mamdoh"); 
	_delay_ms(1500);
	LCD_Clear();
}

void CheckIfPasswordIsStoredInEEPROM (void)
{
	Pass_Flag= EEPROM_ReadByte(EEPROM_ADDRESS , PASSWORD_FLAG_ADRESS);
	_delay_ms(5);
	if (Pass_Flag == 0)
	{
		Return_Byte=0;
		SetNewPinForFirstTimeOnly();
		Return_Byte=0;
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("1-Set New Pin:");
		LCD_GoTo(1,0);
		LCD_WriteString("2-Login:");
		ServoMotor_Home();
	}
	else if (Pass_Flag == 1)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("1-Set New Pin:");
		LCD_GoTo(1,0);
		LCD_WriteString("2-Login:");
		ServoMotor_Home();
	}
	
}

void SetNewPinForFirstTimeOnly (void)
{
	uint8 i=0 ;
	LCD_GoTo(0,0);
	LCD_WriteString("Life Time PIN :");
	if (Return_Byte == 0)
	{
		while (i < PASSWORD_SIZE)
		{
			Return_Byte = UART_ReceivedByte_Status();
			if (Return_Byte == 1)
			{
				Password[i] = UART_RECEIVED_BYTE;
				LCD_GoTo(1,i);
				LCD_WriteChar('*');
				i++;
				Return_Byte=0;
			}
			if (i == PASSWORD_SIZE)
			{
				Write_Password_In_EEPROM();
			}
		}
		
	}
}

void Write_Password_In_EEPROM (void)
{
	EEPROM_WriteMultipleBytes(Password , PASSWORD_SIZE , EEPROM_ADDRESS , PASSWORD_ADRESS);
	_delay_ms(5);
	Pass_Flag =1;
	EEPROM_WriteByte(Pass_Flag , EEPROM_ADDRESS , PASSWORD_FLAG_ADRESS);
	_delay_ms(5);
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("PIN SET SUCCESS");
	_delay_ms(1500);
	LCD_Clear();
}

void Right_Password_Sequence (void)
{
	Wrong_Pass_Cntr=0;
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("Welcome");
	ServoMotor_SetAngle18(90);
	_delay_ms(3000);
	ServoMotor_Home();
	Return_Value =0;
	CheckIfPasswordIsStoredInEEPROM();
	
}

void Wrong_Password_Sequence (void)
{
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("Wrong Pin");
	_delay_ms(1500);
	Wrong_Pass_Cntr++;
	if (Wrong_Pass_Cntr < 3)
	{
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("Try Again");
		_delay_ms(1500);
		PIN_Entry_Sequence();
	}
	else
	{
		LED_ON();
		Buzzer_ON();
		_delay_ms(2000);
		LED_OFF();
		Buzzer_OFF();
		Return_Value =0;
		CheckIfPasswordIsStoredInEEPROM();
		Wrong_Pass_Cntr=0;
	}
}

void PIN_Entry_Sequence(void)
{
	uint8 i=0;
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("ENTER PIN:");
	ServoMotor_Home();
	Return_Byte =0;
	LCD_GoTo(1 , 0);
	while (i < PASSWORD_SIZE)
	{
		Return_Byte = UART_ReceivedByte_Status();
		if (Return_Byte == 1)
		{
			UART_Received_Data[i] = UART_RECEIVED_BYTE;
			LCD_WriteChar('*');
			i++;
			Return_Byte=0;
		}
		if (i == PASSWORD_SIZE)
		{
			Return_Value = 1;
		}
	}
	i=0;
	if (Return_Value == 1)
	{
		Pass_Ptr = EEPROM_ReadMultipleBytes(EEPROM_ADDRESS , PASSWORD_ADRESS);
		_delay_ms(5);
		if ((UART_Received_Data[0] == Pass_Ptr[0]) && (UART_Received_Data[1] == Pass_Ptr[1]) && (UART_Received_Data[2] == Pass_Ptr[2]) && (UART_Received_Data[3] == Pass_Ptr[3]) )
		{
			Right_Password_Sequence();
		}
		else
		{
			Wrong_Password_Sequence();
		}
	}
}

void Change_PIN_Sequence(void)
{
	uint8 i=0;
	Pass_Ptr = EEPROM_ReadMultipleBytes(EEPROM_ADDRESS , PASSWORD_ADRESS);
	_delay_ms(5);
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("ENTER OLD PIN:");
	Return_Byte =0;
	LCD_GoTo(1 , 0);
	while (i < PASSWORD_SIZE)
	{
		Return_Byte = UART_ReceivedByte_Status();
		if (Return_Byte == 1)
		{
			UART_Received_Data[i] = UART_RECEIVED_BYTE;
			LCD_WriteChar('*');
			i++;
			Return_Byte=0;
		}
		if (i == PASSWORD_SIZE)
		{
			Return_Value = 1;
		}
	}
	i=0;
	if (Return_Value == 1)
	{
		if ((UART_Received_Data[0] == Pass_Ptr[0]) && (UART_Received_Data[1] == Pass_Ptr[1]) && (UART_Received_Data[2] == Pass_Ptr[2]) && (UART_Received_Data[3] == Pass_Ptr[3]) )
		{
			New_PIN_Entry_Sequence();
			
		}
		else
		{
			 Wrong_Password_Sequence_For_Changing_Pin();  
		}
	}
}

void New_PIN_Entry_Sequence(void)
{
	uint8 i=0;
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("ENTER NEW PIN:");
	Return_Byte =0;
	LCD_GoTo(1 , 0);
	while (i < PASSWORD_SIZE)
	{
		Return_Byte = UART_ReceivedByte_Status();
		if (Return_Byte == 1)
		{
			Password[i] = UART_RECEIVED_BYTE;
			LCD_WriteChar('*');
			i++;
			Return_Byte=0;
		}
		if (i == PASSWORD_SIZE)
		{
			Return_Value = 1;
		}
	}
	i=0;
	if (Return_Value == 1)
	{
		Write_Password_In_EEPROM ();
		CheckIfPasswordIsStoredInEEPROM();
	}
	
}

void Wrong_Password_Sequence_For_Changing_Pin (void)
{
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteString("Wrong Pin");
	_delay_ms(1500);
	Wrong_Pass_Cntr++;
	if (Wrong_Pass_Cntr < 3)
	{
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("Try Again");
		_delay_ms(1500);
		Change_PIN_Sequence();
	}
	else
	{
		LED_ON();
		Buzzer_ON();
		_delay_ms(2000);
		LED_OFF();
		Buzzer_OFF();
		Return_Value =0;
		CheckIfPasswordIsStoredInEEPROM();
		Wrong_Pass_Cntr=0;
	}
}
