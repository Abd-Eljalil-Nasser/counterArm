void LCD_command(unsigned char command)
{
GPIO_PORTA_DATA_R = 0; /* RS = 0, R/W = 0 */
GPIO_PORTB_DATA_R = command;
GPIO_PORTA_DATA_R = EN; /* pulse E */
SYSTICK_delay(0);
GPIO_PORTA_DATA_R = 0;
if (command < 4)
SYSTICK_delay(10); /* command 1 and 2 needs up to 1.64ms */
else
SYSTICK_delay(1); /* all others 40 us */
}
