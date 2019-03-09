
#include "PORT.h"


void Port_Init(Port port_index)
{
	
	 uint32_t  Port_base;
	
	SET_BIT(SYSCTL_RCGCGPIO_R,port_index);
	while(BIT_IS_CLEAR(SYSCTL_PRGPIO_R,port_index));

	
	switch(port_index)
	{
		
		case PORT_A : Port_base=GPIO_PORT_A_APB_BASE_ADDRESSE;
									break;
		
		case PORT_B : Port_base=GPIO_PORT_B_APB_BASE_ADDRESSE;
									break;
					
		case PORT_C : Port_base=GPIO_PORT_C_APB_BASE_ADDRESSE;
									break;
					
		case PORT_D : Port_base=GPIO_PORT_D_APB_BASE_ADDRESSE;
									break;
					
		case PORT_E : Port_base=GPIO_PORT_E_APB_BASE_ADDRESSE;
									break;
					
		case PORT_F : Port_base=GPIO_PORT_F_APB_BASE_ADDRESSE;
									break;
			
	}



	/* Lock register */
						
	(*((volatile uint32_t *)((Port_base + GPIO_PORT_LOCK_R_OFFSET))))=UNLOCK_32_BIT_VALUE;
		

	/*Commit Register*/
					
	(*((volatile uint32_t *)((Port_base +GPIO_PORT_CR_R_OFFSET ))))|=0x0000000F;


	/*Digital Enable Register*/
	  			
        (*((volatile uint32_t *)(Port_base +GPIO_PORT_DEN_R_OFFSET)))|=(0X0000001F);


	/*Alternative Function Select Register*/
				
        (*((volatile uint32_t *)((Port_base +GPIO_PORT_AFSEL_R_OFFSET))))&=~(0X0000001F);


	/*Analog Mode Select Register */
				
        (*((volatile uint32_t *)((Port_base +GPIO_PORT_AMSEL_R_OFFSET))))&=~(0X0000001F);
	
	
}

void Port_SetPinDirection(uint8 port_index, uint8 pins_mask , Port_PinDirectionType I_O )
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