uint8 DIO_ReadPort (Port port_index, uint8 pins_mask) {
    switch (port_index) {
	
        // Port A
        case 0 : return GPIO_PORTA_DATA_R & pins_mask;
    

        // Port B
        case 1 : return  GPIO_PORTB_DATA_R & pins_mask;
       

        // Port C
        case 2 : return GPIO_PORTC_DATA_R & pins_mask;
				

        // Port D
        case 3 : return GPIO_PORTD_DATA_R & pins_mask;      
       

        // Port E
        case 4 : return GPIO_PORTE_DATA_R & pins_mask; 
        
        
        // Port F 
        case 5 : return GPIO_PORTF_DATA_R & pins_mask;  
       
		
		}
		
	}

	
