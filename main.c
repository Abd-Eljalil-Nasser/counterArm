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

//set direction of port c as input
void Port_SetPinDirection(2,3,0);
  
// connect first 3 bit from port to pull down resitance
void Port_SetPinPullDown(2,3,1);
  
//our increment variable
uint16 increment_counter = 0;
// portc pin 0 reset 
//portc pin 1 increament
//portc pin 2 increament
while (1)
{
      if (DIO_ReadPort(2,0)==1)
	    {
           while (DIO_ReadPort(2,0)==1)
           {;
            }
        increment_counter =0;
        }
      else if (DIO_ReadPort(2,1)==1)
        {
           while (1)
           {
           increment_counter++;
           SYSTICK_delay(200);
               if (DIO_ReadPort(2,1)==1)
               {
               break;
               }
           }
       }
      else if (DIO_ReadPort(2,2)==1)
	    {
         increment_counter--;
            while (DIO_ReadPort(2,2)==1)
            {;
            }
        }
}
}


