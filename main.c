#include "PORT.h"
#include "DIO.h"
#include "SSD.h"
#include "systick.h"
#include "tm4c123gh6pm.h"

void main(void)
{
//port A Port B as output for 7 segment display
void Port_Init(0);
void Port_Init(1);
//Port C as input from push buttons
void Port_Init(2);
  
//set direction for output ports"A , B"
void Port_SetPinDirection(0,7 ,1);
void Port_SetPinDirection(1,7,1);

//set direction of port d as input
void Port_SetPinDirection(3,3,0);
  
// connect first 3 bit from port d to pull down resitance
void Port_SetPinPullDown(3,3,1);

 //initialization of 7-segment
 //Please if you  add parameter to function tell us
 Seven_Segment_init();

//our increment variable
uint16 increment_counter = 0;
// portd pin 0 reset 
//portd pin 1 increament
//portd pin 2 increament
	

while (1)
	{
	      if (DIO_ReadPort(3,0)==1) //reset condition
		{
		   while (DIO_ReadPort(3,0)==1)
		    {;
		    }
		   increment_counter =0;
		   //to display the result
		   Seven_Segment_Display();
		}
	      else if (DIO_ReadPort(3,1)==1) //increment condition
		{
		   while (1)
		 	  {
			       increment_counter++;
				   //to display the result
		   		   Seven_Segment_Display();
			       SYSTICK_delay(200);
			       if (DIO_ReadPort(3,1)==1)
				       {
				       break;
				       }
		           }
	       }
	      else if (DIO_ReadPort(3,2)==1) //decreament condition
		    {
		 		increment_counter--;
				 //to display the result
		   		 Seven_Segment_Display();
		        while (DIO_ReadPort(3,2)==1)
			    {;
			    }	
		    }
	}//end of big while
}//end of void


