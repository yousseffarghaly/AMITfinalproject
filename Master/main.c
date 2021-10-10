/*
 * main.c
 *
 * Created: 10/8/2021 4:26:45 PM
 *  Author: hp
 */ 


#include "SPI.h"
#include "UART.h"

int main(void)
{
	uint_8 bluetooth , data=0 ;
	UART_Init();
	DIO_voidSetPinDir(PORTC,PIN2,OUTPUT);
	SPI_Master_Init();
    while(1)
    { 
		bluetooth=UART_Rx();
		data=SPI_Transiver(bluetooth);
		if (((uint_8)bluetooth & 1)== 1 )
		{
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			bluetooth=0;
		}
	    else if (((uint_8)bluetooth & 1)== 0)
	    {
			DIO_voidSetPinValue(PORTC,PIN2,LOW);
			bluetooth=0;
	    }
	    
			
	        
    }
       
}