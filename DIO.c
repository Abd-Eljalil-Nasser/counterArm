#include "DIO.h"


// Toggle Function 


void DIO_FlipPort (uint8 port_index, uint8 pins_mask) {
    switch (port_index) {
        // Port A
        case 0 : GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R ^ pins_mask;
        break ;

        // Port B
        case 1 : GPIO_PORTB_DATA_R = GPIO_PORTB_DATA_R ^ pins_mask;
        break ;

        // Port C
        case 2 : GPIO_PORTC_DATA_R = GPIO_PORTC_DATA_R ^ pins_mask;
				break ;

        // Port D
        case 3 : GPIO_PORTD_DATA_R = GPIO_PORTD_DATA_R ^ pins_mask;      
        break ;

        // Port E
        case 4 : GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R ^ pins_mask; 
        break ;
        
        // Port F 
        case 5 : GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ pins_mask;  
        break ;
   
        
    }

}
