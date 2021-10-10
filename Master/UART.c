/*
 * UART.c
 *
 * Created: 10/8/2021 4:51:46 PM
 *  Author: youssef
 */ 

#include "UART.h"
#define UART_BAUDRATE_9600 (0x67)

 void UART_Init(void)
 {
	 // RX-TX direction 
	DIO_voidSetPinDir(PORTD,PIN0,OUTPUT);
	DIO_voidSetPinDir(PORTD,PIN1,INPUT);
	// baud rate 
	UART_UBRRL_REG = (uint_8)UART_BAUDRATE_9600 ;
	SET_BIT(UART_UCSRB_REG,3);//  Transmitter Enable
	SET_BIT(UART_UCSRB_REG,4);//  Receiver Enable
	// Register UCSRS BIT 7 , 8 BITS TRANSFER, NO PARITY CHECK, 1 BIT STOP
	UART_UCSRC_REG |=(1<<7)|(3<<1)|(1<<3);
	
 }
 void UART_Tx(uint_8 Data)
 {
	 /* wait for empty transmit buffer*/
	 while((GET_BIT(UART_UCSRA_REG,5))==0);
	 /* data into buffer for sending */
	 UART_UDR_REG=Data;
 }
 uint_8 UART_Rx(void)
 {
	 /* wait for data*/
	 while((GET_BIT(UART_UCSRA_REG,7))==0);
	 /* return received data from buffer */
	 return UART_UDR_REG;
 }