/*
first part 

definision of ADC converter in ATMEGA32



second part

collect data from ADC one by one and choose the biggest one
ADC used to measure the intensity of light using LDR

*/



unsigned int readADC0()
{
	ADMUX = 0x00;
	ADCSRA = 0x00;
	ADMUX |= (1 << REFS0);
	//ADMUX |= (0 << ADLAR);
	ADMUX |= (0<<MUX4) |(0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (0 << MUX0);
	ADCSRA |=(1<<ADEN)|(1<<ADPS0);
	ADCSRA |= (1 << ADSC);
	return ADC;
}

unsigned int readADC1()
{
	ADMUX = 0x00;
	ADCSRA = 0x00;
	ADMUX |= (1 << REFS0);
	//ADMUX |= (0 << ADLAR);
	ADMUX |= (0<<MUX4) |(0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (1 << MUX0);
	ADCSRA |=(1<<ADEN)|(1<<ADPS0);
	ADCSRA |= (1 << ADSC);
	return ADC;
}

unsigned int readADC2()
{
	ADMUX = 0x00;
	ADCSRA = 0x00;
	ADMUX |= (1 << REFS0);
	//ADMUX |= (0 << ADLAR);
	ADMUX |= (0<<MUX4) |(0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (0 << MUX0);
	ADCSRA |=(1<<ADEN)|(1<<ADPS0);
	ADCSRA |= (1 << ADSC);
	return ADC;
}


unsigned int readADC3()
{
	ADMUX = 0x00;
	ADCSRA = 0x00;
	ADMUX |= (1 << REFS0);
	//ADMUX |= (0 << ADLAR);
	ADMUX |= (0<<MUX4) |(0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (1 << MUX0);
	ADCSRA |=(1<<ADEN)|(1<<ADPS0);
	ADCSRA |= (1 << ADSC);
	return ADC;
}


//***************************************************************************



VoltADC = readADC0()/310.3;
now_check = wypisz(VoltADC);
max = now_check;

VoltADC = readADC1()/310.3;
now_check = wypisz(VoltADC);
if(max < now_check)
{
	max = now_check;
}

VoltADC = readADC2()/310.3;
now_check = wypisz(VoltADC);
if(max < now_check)
{
	max = now_check;
}


VoltADC = readADC3()/310.3;
now_check = wypisz(VoltADC);
if(max < now_check)
{
	max = now_check;
}