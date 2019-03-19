void LCD_sendCommand(uint8 command){
    
    DIO_WritePort(PORT_A,0xFF,STD_LOW);
    DIO_WritePort(PORT_B,0xFF,STD_LOW);
    
    SYSTICK_delay(1);

    DIO_WritePort(PORT_B,0XFF,STD_LOW);

    SYSTICK_delay(1);
    
    DIO_WritePort(PORT_B,command,STD_HIGH);
    DIO_WritePort(PORT_A,EN,STD_HIGH);
    
    SYSTICK_delay(10);
 
    
}