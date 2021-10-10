/*
 * main.c
 *
 * Created: 10/8/2021 7:59:50 PM
 *  Author: hp
 */ 


#include "SPI.h"
int main(void)
{
	uint_8 data =0 , dummy =0;
	/*Set Outputs Direction*/
	DIO_voidSetPinDir(PORTD,PIN3,OUTPUT);
	DIO_voidSetPinDir(PORTC,PIN2,OUTPUT);
	SPI_Slave_Init();
	
    while(1)
    {
       data=SPI_Transiver(dummy);
	   if (((uint_8)data & 1)== 1 )
	   {
		   DIO_voidSetPinValue(PORTC,PIN2,HIGH);
		   DIO_voidSetPinValue(PORTD,PIN3,HIGH);
		   data=0;
	   }
	   else if (((uint_8)data & 1)== 0)
	   {
		   DIO_voidSetPinValue(PORTC,PIN2,LOW);
		   DIO_voidSetPinValue(PORTD,PIN3,LOW);
		   data=0;
	   }
    }
}