/*
 * SPI.c
 *
 * Created: 10/8/2021 6:22:46 PM
 *  Author: youssef
 */ 
#include "SPI.h"
#include "REG.h"
void SPI_Master_Init(void)
{
	//SPI MOSI AS OUTPUT
	DIO_voidSetPinDir(PORTB,5,OUTPUT);
	//SPI SS AS OUTPUT
	DIO_voidSetPinDir(PORTB,4,OUTPUT);
	//SPI SCK AS OUTPUT
	DIO_voidSetPinDir(PORTB,7,OUTPUT);
	//SPI MISO AS IUTPUT
	DIO_voidSetPinDir(PORTB,6,INPUT);
	DIO_voidSetPinValue(PORTB,4,HIGH);
	//SPI Enable
	SET_BIT(SPI_SPCR_REG,6);
	// Master select 
	SET_BIT(SPI_SPCR_REG,4);
	// frequency 
	SET_BIT(SPI_SPCR_REG,1);
	DIO_voidSetPinValue(PORTB,4,LOW);

}
void SPI_Slave_Init(void)
{
	//SPI MOSI AS INPUT
	DIO_voidSetPinDir(PORTB,5,INPUT);
	//SPI SS AS INPUT
	DIO_voidSetPinDir(PORTB,4,INPUT);
	//SPI SCK AS INPUT
	DIO_voidSetPinDir(PORTB,7,INPUT);
	//SPI MISO AS OUTPUT
	DIO_voidSetPinDir(PORTB,6,OUTPUT);
	//SPI Enable
	SET_BIT(SPI_SPCR_REG,6);
	// Slave select
	CLR_BIT(SPI_SPCR_REG,4);
}
uint_8 SPI_Transiver(uint_8 data)
{
	SPI_SPDR_REG=data;
	//Wait for Flag
	while((GET_BIT(SPI_SPSR_REG,7))==0);
	return SPI_SPDR_REG;
}