void DIO_WritePort(Port port_index , uint8 pins_mask, DIO_LevelType pin_level){
		switch (port_index) {
        // Port A
				//check for the value of pin_level
        case 0 : if(pin_level){
					GPIO_PORTA_DATA_R |= pins_mask; //if high set the required pins by pins_mask
				} 
				else{
							GPIO_PORTA_DATA_R &= ~(pins_mask);//if low clear the required pins by pins_mask
				}
        break ;

        // Port B
        case 1 : if(pin_level){
					GPIO_PORTB_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTB_DATA_R &= ~(pins_mask);
				}
        break ;

        // Port C
        case 2 : if(pin_level){
					GPIO_PORTC_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTC_DATA_R &= ~(pins_mask);
				}
				break ;

        // Port D
        case 3 : if(pin_level){
					GPIO_PORTD_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTD_DATA_R &= ~(pins_mask);
				} 
        break ;

        // Port E
        case 4 : if(pin_level){
					GPIO_PORTE_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTE_DATA_R &= ~(pins_mask);
				}
        break ;
        
        // Port F 
        case 5 : if(pin_level){
					GPIO_PORTF_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTF_DATA_R &= ~(pins_mask);
				}  
        break ;
   
        
    }
  }
