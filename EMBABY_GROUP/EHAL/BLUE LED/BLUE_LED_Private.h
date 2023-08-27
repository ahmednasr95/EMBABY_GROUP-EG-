/*
 * BLUE_LED_Private.h
 *
 * Created: 8/20/2023 10:15:36 AM
 *  Author: aliae
 */ 


#ifndef BLUE_LED_PRIVATE_H_
#define BLUE_LED_PRIVATE_H_

// Configuration:
#include "CPU_Configuration.h"

#define BLUE_LED_PIN		DIO_PIN5
#define BLUE_LED_PORT		DIO_PORTA

#define BLUE_LED_OUTPUT		DIO_OUTPUT

#define BLUE_LED_HIGH		DIO_HIGH
#define BLUE_LED_LOW		DIO_LOW

// Function Prototype:
void BLUE_LED_Initializ(void);
void BLUE_LED_ON(void);
void BLUE_LED_OFF(void);
void BLUE_LED_TGL(void);
UINT8_t BLUE_LED_STATUS(void);


#endif /* BLUE_LED_PRIVATE_H_ */