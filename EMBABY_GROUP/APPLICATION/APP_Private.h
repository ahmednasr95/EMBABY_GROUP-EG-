/*
 * APP_Private.h
 *
 * Created: 8/20/2023 10:53:04 AM
 *  Author: aliae
 */ 


#ifndef APP_PRIVATE_H_
#define APP_PRIVATE_H_

#define NUM_50MILLIS_DELAYS 100
#define DELAY_50MILLIS	_delay_ms(50);

#include "RED_LED_Private.h"
#include "BLUE_LED_Private.h"
#include "GREEN_LED_Private.h"
#include "YELLOW_LED_Private.h"
#include "LCD_Private.h"

void initializations(void);
void traffic_light_app(void);

void STOP_State(void);
void SLOW_DOWN_State(void);
void GO_State(void);

#endif /* APP_PRIVATE_H_ */