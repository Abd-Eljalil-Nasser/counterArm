void Port_SetPinPullDown(Port port_index, uint8 pins_mask, uint8 enable)
{
    if(enable)
    {
        switch(port_index)
        {

            case PORT_A :
                GPIO_PORTA_PDR_R |= pins_mask;
                                        break;

            case PORT_B :
                GPIO_PORTB_PDR_R |= pins_mask;
                                        break;

            case PORT_C :
                GPIO_PORTC_PDR_R |= pins_mask;
                                        break;

            case PORT_D :
                GPIO_PORTD_PDR_R |= pins_mask;
                                        break;

            case PORT_E :
                GPIO_PORTE_PDR_R |= pins_mask;
                                        break;

            case PORT_F :
                GPIO_PORTF_PDR_R |= pins_mask;
                //SET_BIT(GPIO_PORTF_PDR_R,pins_mask);
                                        break;

        }

    }
    else if(enable == 0 )
    {
            switch(port_index)
        {

            case PORT_A :
                 GPIO_PORTA_PDR_R &= ~pins_mask;
                                        break;

            case PORT_B :
                GPIO_PORTB_PDR_R &= ~pins_mask;
                                        break;

            case PORT_C :
                GPIO_PORTC_PDR_R &= ~pins_mask;
                                        break;

            case PORT_D :
                GPIO_PORTD_PDR_R &= ~pins_mask;
                                        break;

            case PORT_E :
                GPIO_PORTE_PDR_R &= ~pins_mask;
                                        break;

            case PORT_F :
                GPIO_PORTF_PDR_R &= ~pins_mask;
                                        break;

        }
    }
}
