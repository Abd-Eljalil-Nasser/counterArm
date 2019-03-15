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
 
}


