/*
 * BLUE_LED_Interface.c
 *
 * Created: 8/20/2023 10:18:53 AM
 *  Author: aliae
 */ 
#include "BLUE_LED_Private.h"

void BLUE_LED_Initializ(void){
	DIO_SetPin_Direction(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_OUTPUT);
}
void BLUE_LED_ON(void){
	DIO_SetPin_Value(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_HIGH);
}
void BLUE_LED_OFF(void){
	DIO_SetPin_Value(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_LOW);
}
void BLUE_LED_TGL(void){
	DIO_TglPin_Value(BLUE_LED_PORT,BLUE_LED_PIN);
}
UINT8_t BLUE_LED_STATUS(void){
	return DIO_GetPin_Value(BLUE_LED_PORT, BLUE_LED_PIN);
}