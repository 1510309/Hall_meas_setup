/*
 * adc.c
 *
 * Created: 01.03.2016 19.36.13
 *  Author: magnehh
 */ 

#include <avr/io.h>

void initADC(void){
	PRR &= ~_BV(PRADC);
	ADMUX = _BV(REFS0);
	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
	ADCSRB = 0x00;
	DIDR0 = 0xFF;
}

uint16_t readADC(uint8_t channel){
	ADMUX = ((ADMUX & 0xF0) | channel);
	ADCSRA |= _BV(ADSC);
	while (ADCSRA & _BV(ADSC));
	return ADC;
}

void disableADC(void){
	ADCSRA = 0x00;
	DIDR0 = 0x00;
	PRR |= _BV(PRADC);
}