
/* implementacja SPI 
konieczna do tego by komunikowaæ siê 
z kart¹ SD

implementation of SPI, necessary to communication 
between AVR and SD card 

*/


void SPI_init (void) // Initialize SPI Master Device (without interrupt)
{
	DDRB = (1<<5)|(1<<7)|(1<<4);
	DDRB &= ~(1<<6);
	PORTB |= _BV(4);
	
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPI2X);// Enable SPI, Set as Master, prescaler: Fosc/16, Enable Interrupts
}

uint8_t SPI_status(void) 
{
	return SPSR; //status
}


void SPI_write(uint8_t* p, int size, uint8_t addr)  // Write out all characters in supplied buffer to register at address
{
	int i;
	for (i = 0; i < size; ++i) 
	{
		while(!(SPSR & (1<<SPIF) )); // wait until transmission will be done
		SPDR = p[i];
	}
}


void SPI_read(uint8_t* p, int size, uint8_t addr) // Read size number of characters into buffer p from register at address
{
	int i;
	for (i = 0; i < size; ++i) 
	{
		while(!(SPSR & (1<<SPIF) ));
		p[i] = SPDR;
	}
}