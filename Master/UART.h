/*
 * UART.h
 *
 * Created: 10/8/2021 4:51:21 PM
 *  Author: hp
 */ 


#ifndef UART_H_
#define UART_H_
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "REG.h"
#include "DIO_interface.h"
void UART_Init(void);
void UART_Tx(uint_8 Data);
uint_8 UART_Rx(void);





#endif /* UART_H_ */