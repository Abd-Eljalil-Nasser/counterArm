#include "SSD.h"
#include <stdlib.h>




void Seven_Segment_init(){
	uint32_t delay;
	SYSCTL_RCGCGPIO_R |= 0x07; //to connect the first 3 ports to the clock(not sure about it)
	
	
	//initiating portA
	Port_Init(PORT_A);
	Port_SetPinDirection(PORT_A, 0x3c , 1 ); // we put 1 because we want it to be output to the seven segment
	//pins: PA2,PA3,PA4,PA5
	
	
	//initiating portB
	Port_Init(PORT_B);
	Port_SetPinDirection(PORT_B, 0xcc , 1 ); //pins: PB2,PB3,PB6,PB7
	
	
	//initiating portC
	Port_Init(PORT_C);
	Port_SetPinDirection(PORT_C, 0xF0 , 1 ); //pins: PC4,PC5,PC6,PC7
	
	
}

void DecToBinary_write(int n, Port port_index) {
	char Bin[4];
	int digit;
	for(int i = 0; i<4 ; i++){
		Bin[i] = n % 2;
		n/= 2;
	}
	switch(port_index){
		case PORT_A : PA2 = Bin[0]; //to write in portA
			PA3 = Bin[1];
		  PA4 = Bin[2];
		  PA5 = Bin[3];
		break;
		
		case PORT_B : PB2 = Bin[0]; //to write in portB
		  PB3 = Bin[1];
		  PB6 = Bin[2];
		  PB7 = Bin[3];
		break;
		
					
		case PORT_C : PC4 = Bin[0]; //to write in portC
			PC5 = Bin[1];
		  PC6 = Bin[2];
		  PC7 = Bin[3];
		break;
	}
		
}
	

void Seven_Segment_Display(int digit){

		uint8 buf [3];
		uint8 digit1, digit2,digit3;
		itoa(digit,buf,4);

		digit1 = atoi(buf[0]);
		digit2 = atoi(buf[1]);
		digit3 = atoi(buf[2]);
		
		 DecToBinary_write(digit1 , PORT_A);
		 DecToBinary_write(digit2 , PORT_B);
		 DecToBinary_write(digit3 , PORT_C);
}


