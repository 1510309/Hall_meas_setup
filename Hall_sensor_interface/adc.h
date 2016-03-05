/*
 * IncFile1.h
 *
 * Created: 01.03.2016 19.34.29
 *  Author: magnehh
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

typedef enum {ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7, ADC8} input_channel;

void initADC(void);
uint16_t readADC(uint8_t);
void disableADC(void);



#endif /* INCFILE1_H_ */