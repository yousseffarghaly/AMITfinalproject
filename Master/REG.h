#ifndef			REG_H
#define			REG_H

/*				PORTA Registers								*/
#define			PORTA_REG			*((volatile uint_8 *)0x3B)
#define			DDRA_REG			*((volatile uint_8 *)0x3A)
#define			PINA_REG			*((volatile uint_8 *)0x39)
/*				PORTB Registers								*/
#define			PORTB_REG			*((volatile uint_8 *)0x38)
#define			DDRB_REG			*((volatile uint_8 *)0x37)
#define			PINB_REG			*((volatile uint_8 *)0x36)
/*				PORTC Registers								*/
#define			PORTC_REG			*((volatile uint_8 *)0x35)
#define			DDRC_REG			*((volatile uint_8 *)0x34)
#define			PINC_REG			*((volatile uint_8 *)0x33)
/*				PORTD Registers								*/
#define			PORTD_REG			*((volatile uint_8 *)0x32)
#define			DDRD_REG			*((volatile uint_8 *)0x31)
#define			PIND_REG			*((volatile uint_8 *)0x30)

/*				UART Registers								*/
#define UART_UBRRH_REG (*((volatile uint_8*)0x40))
#define UART_UBRRL_REG (*((volatile uint_8*)0x29))
#define UART_UCSRA_REG (*((volatile uint_8*)0x2B))
#define UART_UCSRB_REG (*((volatile uint_8*)0x2A))
#define UART_UCSRC_REG (*((volatile uint_8*)0x40))
#define UART_UDR_REG (*((volatile uint_8*)0x2C))

/*              SPI Registers  */
#define SPI_SPCR_REG (*(volatile uint_8*)0x2D)
#define SPI_SPSR_REG (*(volatile uint_8*)0x2E)
#define SPI_SPDR_REG (*(volatile uint_8*)0x2F)

#endif