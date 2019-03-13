#include "SSD.h"





void Seven_Segment_init(uint8 pins_mask){
	uint32_t delay;
	SYSCTL_RCGCGPIO_R |= 0x07;
	delay = 1; //dummy variable to check for the clock 
	//initiating portA
	
	GPIO_PORTA_AFSEL_R = 0;
	GPIO_PORTA_AMSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_DIR_R = pins_mask;
	GPIO_PORTA_DEN_R = pins_mask;
	GPIO_PORTA_CR_R = pins_mask;
	
	//initiating portB
	GPIO_PORTB_AFSEL_R = 0;
	GPIO_PORTB_AMSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTB_DIR_R = pins_mask;
	GPIO_PORTB_DEN_R = pins_mask;
	GPIO_PORTB_CR_R = pins_mask;
	
	//initiating portC
	GPIO_PORTC_AFSEL_R = 0;
	GPIO_PORTC_AMSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTC_DIR_R = pins_mask;
	GPIO_PORTC_DEN_R = pins_mask;
	GPIO_PORTC_CR_R = pins_mask;
	
	
}

void DecToBinary(int n) {
	int Bin[4];
	for(int i = 0; i<4 ; i++){
		Bin[i] = n % 2;
		n/= 2;
	}
}
	

void Seven_Segment_Display(int digit1 , int digit2 , int digit3){
		
		DecToBinary(digit1);
		DecToBinary(digit2);
		DecToBinary(digit3);
}


