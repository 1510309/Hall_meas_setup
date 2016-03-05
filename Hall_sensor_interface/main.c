/*
 * Hall_sensor_interface.c
 *
 * Created: 01.03.2016 18.36.48
 * Author : magnehh
 */ 

#include "settings.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "adc.h"
#include "uart.h"



int main(void){
	initADC();
	uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
	char buffer[7];
    DDRB |= _BV(PB5);
	sei();
    while (1){
		uint16_t adc_value_x = readADC(ADC0);
		uint16_t adc_value_y = readADC(ADC3);
		
		if ((adc_value_x < (512 - THRESHOLD_VAL) || adc_value_x > (512 + THRESHOLD_VAL)) || (adc_value_y < (512 - THRESHOLD_VAL) || adc_value_y > (512 + THRESHOLD_VAL))){
			PORTB |= _BV(PB5);
		}else{
			PORTB &= ~_BV(PB5);
		}
		
		uart_putc('X');
		uart_putc(' ');
		uart_puts(ultoa(adc_value_x,buffer,10));
		uart_putc('\n');
		uart_putc('\r');
		
		uart_putc('Y');
		uart_putc(' ');
		uart_puts(ultoa(adc_value_y,buffer,10));
		uart_putc('\n');
		uart_putc('\r');
		
		_delay_ms(50);
    }
}

