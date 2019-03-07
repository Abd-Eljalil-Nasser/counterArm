#ifndef DIO_H
#define DIO_H

char DIO_ReadPort(uint8 port_index , uint8 pins_mask);
/*Return the value of the pins selected by
pins_masks in the port selected by port_index*/

void DIO_WritePort(uint8 port_index , uint8 pins_mask, char pins_level);
/*change the value of the pins selected by pins_masks
in the port selected by port_index to input pins_level*/

void DIO_FlipPort (uint8 port_index, uint8 pins_mask);
/*Toggle the values of the pins selected by pin_masks
in the port selected by port_index*/

#endif