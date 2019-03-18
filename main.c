#include "PORT.h"
#include "DIO.h"
//#include "SSD.h"
#include "systick.h"
#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "TM4C123GH6PM.h"

void LCD_command(unsigned char command)
{
GPIO_PORTA_DATA_R = 0; /* RS = 0, R/W = 0 */
GPIO_PORTB_DATA_R = command;
GPIO_PORTA_DATA_R = EN; /* pulse E */
SYSTICK_delay(0);
GPIO_PORTA_DATA_R = 0;
if (command < 4)
SYSTICK_delay(10); /* command 1 and 2 needs up to 1.64ms */
else
SYSTICK_delay(1); /* all others 40 us */
}





int main()
{
	//port A Port B as output for 7 segment display

	// void Port_Init(0);
	// void Port_Init(1);
	// void Port_Init(2);
		
	//Port D as input from push buttons
	Port_Init(PORT_D);	
	//set direction for output ports"A , B"
	// void Port_SetPinDirection(0,7 ,1);
	// void Port_SetPinDirection(1,7,1);
	// void Port_SetPinDirection(2,7,1);

	//set direction of port d as input
	Port_SetPinDirection(PORT_D,0x07,PORT_PIN_IN);
	
	// connect first 3 bit from port d to pull down resitance
	Port_SetPinPullDown(PORT_D,0x07,1);

	//initialization of 7-segment
	//Please if you  add parameter to function tell us
	//  Seven_Segment_init();
	
	LCD_init();

	//our increment variable
	uint16 increment_counter = 0;
	// portd pin 0 reset 
	//portd pin 1 increament
	//portd pin 2 increament
	

	while (1)
	{SYSTICK_delay(10);
	//	LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
	      if (DIO_ReadPort(PORT_D,0x08)==0x08) //reset condition
		{
			SYSTICK_delay(10);
		   while (DIO_ReadPort(PORT_D,0x08)==0x08);
		   increment_counter =0;
		   //to display the result

		  LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
		  SYSTICK_delay(10);
		  LCD_integerToString(increment_counter);

		//    Seven_Segment_Display(increment_counter);
		}
	      else if (DIO_ReadPort(PORT_D,0x40)== 0x40) //increment condition
				{	SYSTICK_delay(10);
		   while (DIO_ReadPort(PORT_D,0x40)== 0x40)
		 	  {
			      increment_counter++;
						//to display the result
						//    Seven_Segment_Display(increment_counter);
			   		LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
						SYSTICK_delay(10);
						LCD_integerToString(increment_counter);
						SYSTICK_delay(500);
						//    if (DIO_ReadPort(3,1)==1)
						//        {
						//        break;
						//        }
		        //    }
	       }
			 }
	      else if((DIO_ReadPort(PORT_D,0x04) == 0x04)) //decreament condition
		    {
						SYSTICK_delay(10);
						increment_counter--;
						//to display the result
						//  Seven_Segment_Display(increment_counter);

				    LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
		  			SYSTICK_delay(10);
		  			LCD_integerToString(increment_counter);
					
		        while (DIO_ReadPort(PORT_D,0x04)==0x04);
		    }
		
	}
}


