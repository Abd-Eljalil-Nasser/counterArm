void Port_SetPinPullUp(Port port_index, uint8 pins_mask, uint8 enable)
{
    if(enable)
    {
        switch(port_index)
        {

            case PORT_A :
                GPIO_PORTA_PUR_R |= pins_mask;
                break;

            case PORT_B :
				GPIO_PORTB_PUR_R |= pins_mask;
                break;

            case PORT_C :
                GPIO_PORTC_PUR_R |= pins_mask;
                break;

            case PORT_D :
                GPIO_PORTD_PUR_R |= pins_mask;
                break;

            case PORT_E :
                GPIO_PORTE_PUR_R |= pins_mask;
                break;

            case PORT_F :
                GPIO_PORTF_PUR_R |= pins_mask;
                break;
        }

    }
    else{
		switch(port_index)
        {

            case PORT_A :
                GPIO_PORTA_PUR_R &= ~pins_mask;
                break;

            case PORT_B :
				GPIO_PORTB_PUR_R &= ~pins_mask;
                break;

            case PORT_C :
                GPIO_PORTC_PUR_R &= ~pins_mask;
                break;

            case PORT_D :
                GPIO_PORTD_PUR_R &= ~pins_mask;
                break;

            case PORT_E :
                GPIO_PORTE_PUR_R &= ~pins_mask;
                break;

            case PORT_F :
                GPIO_PORTF_PUR_R &= ~pins_mask;
                break;
        }

	    }
}
