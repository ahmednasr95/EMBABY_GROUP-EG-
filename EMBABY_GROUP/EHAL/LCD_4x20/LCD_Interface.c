
#include "LCD_Private.h"

void LCD_Initialize(void)
{
	//Define direction for pins
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D4, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D5, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D6, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_D7, LCD_OUT);
	
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_RS, LCD_OUT);
	DIO_SetPin_Direction(LCD_CNTRL_PORT, LCD_EN, LCD_OUT);
	_delay_ms(20);
	LCD_Write_Command(0x02);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x0C);
	LCD_Write_Command(0x06);
	LCD_Write_Command(0x01);
	
}
void LCD_Clear(void)
{
	LCD_Write_Command(0x01);
}
void LCD_Write_Command(UINT8_t command)
{
	//Send high nibble first
	//LCD = (LCD & 0x0F) | (command & 0xF0);
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(command,7));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(command,6));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(command,5));
	DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(command,4));
	//Register select will select control register
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_LOW);
	//Write on LCD
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_us(200);
	//Send low nibble
	//LCD =  (LCD & 0x0F) | (command << 4);
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(command,3));
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(command,2));
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(command,1));
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(command,0));
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
}
void LCD_Write_Character(UINT8_t character)
{
	//Send high nibble first
	//LCD = (LCD & 0x0F) | (character & 0xF0);
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(character,7));
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(character,6));
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(character,5));
		DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(character,4));
	//Register select will select data register
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_RS, LCD_HIGH);
	//Write on LCD
	
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_us(200);
	//Send lower nibble
	//LCD =  (LCD & 0x0F) | (character << 4);
			DIO_SetPin_Value(LCD_DATA_PORT,LCD_D7,GET_BIT(character,3));
			DIO_SetPin_Value(LCD_DATA_PORT,LCD_D6,GET_BIT(character,2));
			DIO_SetPin_Value(LCD_DATA_PORT,LCD_D5,GET_BIT(character,1));
			DIO_SetPin_Value(LCD_DATA_PORT,LCD_D4,GET_BIT(character,0));
	//Send high to low pulse
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_us(1);
	DIO_SetPin_Value(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(2);
}
void LCD_Write_String(const char *str)
{
	while (*str != '\0')
	{
		LCD_Write_Character(*str);
		str++;
	}
}
void LCD_Write_Number(UINT32_t number)
{
	UINT32_t num = number;
	UINT16_t digit = 0;
	while(num != 0){
		digit++;
		num/=10;
	}
	if(number == 0){
		LCD_Write_Character('0');
		}else{
		UINT8_t arr_num[digit];
		
		for(int i = digit-1 ; i >= 0 ;i--){
			arr_num[i]=number %10 + '0';
			number/=10;
		}
		//itoa(number , arr_num , 10);
		for(int i =0 ; i<digit;i++){
			LCD_Write_Character(arr_num[i]);
		}
	}
}
void LCD_Write_FloatNumber(fint64_t Fnumber)
{
	UINT32_t intfnumber = (UINT32_t)Fnumber;
	LCD_Write_Number(intfnumber);
	
	fint64_t decimalp = ((Fnumber - (fint64_t)intfnumber) * pow(10, 7));
	
	UINT32_t num = decimalp;
	UINT16_t digit = 0;
	while(num != 0){
		digit++;
		num/=10;
	}
	
	if(digit > 0){
		LCD_Write_Character('.');
		while(digit < 7){
			LCD_Write_Character('0');
			digit++;
		}
		LCD_Write_Number((UINT32_t)decimalp);
	}

}
void LCD_Write_SpecialCharacter(UINT8_t Scharcter)
{
	LCD_Write_Character(Scharcter);
}
void LCD_LINE_position(UINT8_t x , UINT8_t y){
	UINT8_t address =0;
	if(x == 0){
		address = 0x00;
	}
	if(x == 1){
		address = 0x40;
	}
	if(x == 2){
		address = 0x14;
	}
	if(x == 3){
		address = 0x54;
	}
	if(y < 20){
		address += y;
	}
	LCD_Write_Command(0x80+address);
}