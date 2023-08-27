/*
 * EXT_INT_Private.h
 *
 * Created: 8/19/2023 11:47:51 AM
 *  Author: aliae
 */ 


#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

#include "CPU_Configuration.h"

#define INT_REG_CNTR		MCUCR   
#define INT_EN_REQ_PORT		GICR


typedef enum{
	OFF = 0x00,
	ON  = 0x80
}GLB_MODE;

typedef enum{
	INT_LOW_LEVEL=0,
	INT_LOGICAL_CHANGE=1,
	INT_FALLING_EDGE=2,
	INT_RISING_ENDGE=3
	
}INT_mode;
typedef enum{
	INT_1_LOW_LEVEL=0,
	INT_1_LOGICAL_CHANGE=4,
	INT_1_FALLING_EDGE=8,
	INT_1_RISING_ENDGE=12
	
}INT_1_mode;

typedef enum{
	INT_2_FALLING_EDGE=0,
	INT_2_RISING_ENDGE=1
}INT_2_mode; 

typedef enum{
	INT_0_PIN = 0x40
}INT;
typedef enum{
	INT_1_PIN = 0x80
}INT_1;
typedef enum{
	INT_2_PIN = 0x20
}INT_2;

void Set_Global_INT(GLB_MODE mode);
void INT_0_INIT(INT interrupt,INT_mode interrupt_mode);
void INT_1_INIT(INT_1 interrupt,INT_1_mode interrupt_mode);
void INT_2_INIT(INT_2 interrupt_2,INT_2_mode interrupt_2_mode);
void INT_1_DISABLE(void);
void INT_1_ENABLE(void);
#endif /* EXT_INT_PRIVATE_H_ */