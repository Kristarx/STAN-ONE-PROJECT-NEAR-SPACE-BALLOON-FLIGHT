

/* I2C implementation */

void twi_clock_setting(uint16_t clk_KHz) // setting frequency of clock signal
{
	uint8_t clk_div;
	clk_div = ((F_CPU/1000l)/clk_KHz);
	if(clk_div >= 16)
	clk_div = (clk_div-16)/2;
	TWBR = clk_div;
}

void twistart(void) // transmit START condition
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));	//wait for end of transmission
}

void twistop(void) // transmit STOP condition
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while ((TWCR & (1<<TWSTO)));	//wait for end of transmission
}

void twiwrite(char data) // write data
{
	TWDR = data;					//load data into data register
	TWCR = (1<<TWINT) | (1<<TWEN);	//start transmission of data
	while (!(TWCR & (1<<TWINT)));	//wait for end of transmission
}

char twiread(char ack)
// read data
{
	TWCR = ack
	? ((1 << TWINT) | (1 << TWEN) | (1 << TWEA))
	: ((1 << TWINT) | (1 << TWEN)) ;
	while (!(TWCR & (1<<TWINT)));	//wait for end of transmission
	return TWDR;
}