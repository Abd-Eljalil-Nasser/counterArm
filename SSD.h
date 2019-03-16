#include "micro_config.h"
#include "macros.h"
#include "std_types.h"
#include "PORT.h"




void Seven_Segment_init();
//initialization of the Ports and the Pins


void Seven_Segment_Display();
//to display the numbers


void DecToBinary(int n, Port port_index); 
//to convert decimal numbers to binary