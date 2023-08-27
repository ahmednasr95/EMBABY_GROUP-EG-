/*
 * EXT_INT_Interface.c
 *
 * Created: 8/19/2023 11:47:36 AM
 *  Author: aliae
 */ 

#include "EXT_INT_Private.h"

void Set_Global_INT(GLB_MODE mode){
	//SREG |= mode;
}

void INT_0_INIT(INT interrupt,INT_mode interrupt_mode){
	DIO_SetPin_Direction(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	sei();
	INT_REG_CNTR |= interrupt_mode;
	INT_EN_REQ_PORT |= interrupt;
}
void INT_1_INIT(INT_1 interrupt,INT_1_mode interrupt_mode){
	DIO_SetPin_Direction(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	SET_BIT(SREG, 7);
	INT_REG_CNTR |= interrupt_mode;
	INT_EN_REQ_PORT |= interrupt;
}
void INT_2_INIT(INT_2 interrupt_2,INT_2_mode interrupt_2_mode){
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN2,DIO_INPUT);
	sei();
	INT_REG_CNTR |= interrupt_2_mode;
	INT_EN_REQ_PORT |= interrupt_2;
}

void INT_1_DISABLE(void){
	//INT_EN_REQ_PORT &= ~INT_1_PIN;
	CLR_BIT(INT_EN_REQ_PORT,INT1);
}

void INT_1_ENABLE(void){
	INT_EN_REQ_PORT |= INT_1_PIN;
}