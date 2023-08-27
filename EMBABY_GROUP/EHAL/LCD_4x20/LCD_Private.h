/*
 * LCD_Private.h
 *
 * Created: 4/28/2023 10:13:16 PM
 *  Author: aly
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define LCD_DATA_PORT  DIO_PORTB
#define LCD_CNTRL_PORT DIO_PORTA

#define LCD_RS DIO_PIN3
#define LCD_EN DIO_PIN2


#define LCD_D4 DIO_PIN0
#define LCD_D5 DIO_PIN1
#define LCD_D6 DIO_PIN2
#define LCD_D7 DIO_PIN4

#define LCD_OUT  DIO_OUTPUT
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH

// Function Prototype:
void LCD_Initialize(void);
void LCD_Clear(void);
void LCD_Write_Command(UINT8_t command);
void LCD_Write_Character(UINT8_t character);
void LCD_Write_String(const char *str);
void LCD_Write_Number(UINT32_t number);
void LCD_Write_FloatNumber(fint64_t Fnumber);
void LCD_Write_SpecialCharacter(UINT8_t Scharcter);
void LCD_LINE_position(UINT8_t x , UINT8_t y);

#endif /* LCD_PRIVATE_H_ */