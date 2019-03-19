void LCD_init(){

    Port_Init(PORT_A); // Control
    Port_Init(PORT_B); // DATA

    Port_SetPinDirection(PORT_B,0xFF,PORT_PIN_OUT);
    Port_SetPinDirection(PORT_A,0xE0,PORT_PIN_OUT);

    SYSTICK_delay(10);

    LCD_sendCommand(_8_BIT_MODE_1_LINES_5_X_7_DOTS);

    SYSTICK_delay(5);

    LCD_sendCommand(_8_BIT_MODE_1_LINES_5_X_7_DOTS);

    SYSTICK_delay(100);

    LCD_sendCommand(_8_BIT_MODE_1_LINES_5_X_7_DOTS);

    LCD_sendCommand(_8_BIT_MODE_2_LINES_5_X_7_DOTS);
    LCD_sendCommand(RETURN_CURSOR_HOME);
    LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
    LCD_sendCommand(DISPLAY_CURSOR_BLINKING);

}