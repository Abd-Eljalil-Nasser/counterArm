
#include "PORT.h"


void Port_Init(Port PORT_NAME)
{
	
	 uint32_t  Port_base;
	
	SET_BIT(SYSCTL_RCGCGPIO_R,PORT_NAME);
	while(BIT_IS_CLEAR(SYSCTL_PRGPIO_R,PORT_NAME));

	
switch(PORT_NAME)
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