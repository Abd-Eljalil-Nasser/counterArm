void LCD_displayCharacter(uint8 data){
    
    GPIO_PORTA_DATA_R = RS; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTA_DATA_R = EN | RS; /* pulse E */
	SYSTICK_delay(10);
	GPIO_PORTA_DATA_R = 0;
	SYSTICK_delay(40);


}