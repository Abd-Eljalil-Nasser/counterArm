void Port_SetPinPullDown(uint8 port_index, uint8 pins_mask, uint8 enable)
{
    if(enable)
    {
        switch(port_index)
        {

            case PORT_A :
                SET_BIT(GPIO_PORTA_PDR_R,pins_mask);
                                        break;

            case PORT_B :
                SET_BIT(GPIO_PORTB_PDR_R,pins_mask);
                                        break;

            case PORT_C :
                SET_BIT(GPIO_PORTC_PDR_R,pins_mask);
                                        break;

            case PORT_D :
                SET_BIT(GPIO_PORTD_PDR_R,pins_mask);
                                        break;

            case PORT_E :
                SET_BIT(GPIO_PORTE_PDR_R,pins_mask);
                                        break;

            case PORT_F :
                SET_BIT(GPIO_PORTF_PDR_R,pins_mask);
                                        break;

        }

    }
    else if(enable == 0 )
    {
            switch(port_index)
        {

            case PORT_A :
                RESET_BIT(GPIO_PORTA_PDR_R,pins_mask);
                                        break;

            case PORT_B :
                RESET_BIT(GPIO_PORTB_PDR_R,pins_mask);
                                        break;

            case PORT_C :
                RESET_BIT(GPIO_PORTC_PDR_R,pins_mask);
                                        break;

            case PORT_D :
                RESET_BIT(GPIO_PORTD_PDR_R,pins_mask);
                                        break;

            case PORT_E :
                RESET_BIT(GPIO_PORTE_PDR_R,pins_mask);
                                        break;

            case PORT_F :
                RESET_BIT(GPIO_PORTF_PDR_R,pins_mask);
                                        break;

        }
    }
}