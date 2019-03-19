void Port_SetPinDirection(Port port_index, uint8 pins_mask , Port_PinDirectionType I_O )
{

	
	switch(port_index)
	{
		
		case PORT_A : 
			if (I_O){
				GPIO_PORTA_DIR_R |= pins_mask; 
			}else
			{
				GPIO_PORTA_DIR_R &= ~pins_mask;
			}
			
			break;
		
		case PORT_B : 
			if (I_O){
				GPIO_PORTB_DIR_R |= pins_mask; 
			}else
			{
				GPIO_PORTB_DIR_R &= ~pins_mask;
			}
			break;
					
		case PORT_C : 
			if (I_O){
				GPIO_PORTC_DIR_R |= pins_mask; 
			}else
			{
				GPIO_PORTC_DIR_R &= ~pins_mask;
			}
			break;
					
		case PORT_D :
			if (I_O){
				GPIO_PORTD_DIR_R |= pins_mask; 
			}else
			{
				GPIO_PORTD_DIR_R &= ~pins_mask;
			}
			break;
					
		case PORT_E : 
			if (I_O){
				GPIO_PORTE_DIR_R |= pins_mask; 
			}else
			{
				GPIO_PORTE_DIR_R &= ~pins_mask;
			}
			break;
					
		case PORT_F :
			if (I_O){
				GPIO_PORTF_DIR_R |= pins_mask; 
			}else
			{
				GPIO_PORTF_DIR_R &= ~pins_mask;
			} 
			break;
			
	}


}