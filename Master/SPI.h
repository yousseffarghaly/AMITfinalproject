/*
 * SPI.h
 *
 * Created: 10/8/2021 6:23:09 PM
 *  Author: hp
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "REG.h"
#include "DIO_interface.h"
void SPI_Master_Init(void);
void SPI_Slave_Init(void);
uint_8 SPI_Transiver(uint_8 data);





#endif /* SPI_H_ */