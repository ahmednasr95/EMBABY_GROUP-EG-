#include "APP_Private.h"

bool pedestrian_flag = false;

/*
	Inputs: None
	Outputs: None
	Description: Initializes LEDs, LCD, and external interrupt 1 (push button)
*/
void initializations(){
	RED_LED_Initializ();
	BLUE_LED_Initializ();
	GREEN_LED_Initializ();
	YELLOW_LED_Initializ();
	LCD_Initialize();
	INT_1_INIT(INT_1_PIN,INT_1_FALLING_EDGE);
	/*Initialize LCD data*/
	LCD_Write_String("Car");
}

/*
	Inputs: None
	Outputs: None
	Description: 
*/
void traffic_light_app(){
	/*****************Stop State*****************/
	STOP_State();
	/*****************Slow Down State*****************/
	/*Check if pedestrian state occurred in the 'PREVIOUS' state*/
	if(!BLUE_LED_STATUS()){
		SLOW_DOWN_State();
	}else{
		BLUE_LED_OFF();
	}
	/*****************Go State*****************/
	/*Check if pedestrian state occurred in the 'CURRENT' state*/
	if(!pedestrian_flag){
		GO_State();
		SLOW_DOWN_State();
	}else{
		;
	}
}

/*
	Inputs: None
	Outputs: None
	Description: The activation of the red light persists for a duration of 5 seconds, 
	provided that the pedestrian button remains unpressed. However, in the event of button activation, 
	the timer is promptly reset to its initial value of 5 seconds. 
	Subsequently, the pedestrian interrupt feature is temporarily disabled to avert any potential occurrence of an infinite loop. 
	The function controls the red LED to indicate the "stop" state.
*/
void STOP_State(){
	RED_LED_ON();
	for(SINT8_t counter_50ms = NUM_50MILLIS_DELAYS; 0 < counter_50ms; --counter_50ms){
		if(pedestrian_flag){
			pedestrian_flag = false;
			/*Reset the timer*/
			counter_50ms = NUM_50MILLIS_DELAYS;
			BLUE_LED_ON();
			LCD_Clear();
			LCD_Write_String("Pedestrian");
		}
		/*Count Down On Screen*/
		if(counter_50ms % 20 == 0){
			LCD_LINE_position(1, 0);
			LCD_Write_Number(counter_50ms/20);
		}
		DELAY_50MILLIS
	}
	RED_LED_OFF();
	LCD_Clear();
	LCD_Write_String("Car");
}

/*
	Outputs: None
	Inputs: None
	Description: Toggles a yellow LED at regular intervals (500 ms) for 5 seconds. 
	The yellow LED is toggled every 10 iterations of the loop.
	The function controls the yellow LED to indicate the "slow down" state.
	
*/
void SLOW_DOWN_State(){
	for(SINT8_t counter_50ms = NUM_50MILLIS_DELAYS; 0 < counter_50ms; --counter_50ms){
		if(counter_50ms%10 == 0){
			YELLOW_LED_TGL();
		}
		/*Count Down On Screen*/
		if(counter_50ms % 20 == 0){
			LCD_LINE_position(1, 0);
			LCD_Write_Number(counter_50ms/20);
		}
		DELAY_50MILLIS
	}
	YELLOW_LED_OFF();
}

/*
	Outputs: None
	Inputs: None
	Description: Turns on the green LED for 5 seconds unless the `pedestrian_flag` is set, 
	in which case it immediately stops the delays and turns off the green LED. 
	The function controls the green LED to indicate the "go" state.
*/
void GO_State(){
	GREEN_LED_ON();
	for(SINT8_t counter_50ms = NUM_50MILLIS_DELAYS; 0 < counter_50ms; --counter_50ms){
		if(pedestrian_flag){
			break;
		}
		/*Count Down On Screen*/
		if(counter_50ms % 20 == 0){
			LCD_LINE_position(1, 0);
			LCD_Write_Number(counter_50ms/20);
		}
		DELAY_50MILLIS
	}
	GREEN_LED_OFF();
}

ISR(INT1_vect){
	if(!BLUE_LED_STATUS()){
		pedestrian_flag = true;	
	}else{
		
	}
}