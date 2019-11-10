
/* Functions to read and write data
up to the RTC DS3231 using I2C
*/ 


void twiread_ds3231(void)
// function for reading data from ds3231 RTC
{
	twistart();						//START
	twiwrite(ds3231_adr);			//write address of ds3231 for reading operation
	twiwrite(ds3231_REG_TIME);		//base address of internal registers
	twistart();						//START
	twiwrite(ds3231_adr|0x01);		//write address + 1 of ds3231 for reading operation
	rd_ds3231_buf[0] = twiread(ACK);			//read data with ACK
	rd_ds3231_buf[1] = twiread(ACK);			//read data with ACK
	rd_ds3231_buf[2] = twiread(ACK);			//read data with ACK
	rd_ds3231_buf[3] = twiread(ACK);			//read data with ACK
	rd_ds3231_buf[4] = twiread(ACK);			//read data with ACK
	rd_ds3231_buf[5] = twiread(ACK);			//read data with ACK
	rd_ds3231_buf[6] = twiread(NOACK);			//read data with ACK
	twistop();						//STOP
}

void twiwrite_ds3231(uint8_t register_adr, uint8_t data)
// function for writing data to ds3231 RTC
{
	twistart();					//START
	twiwrite(ds3231_adr);		//write address of ds3231 for writing operation
	twiwrite(register_adr);		//base address of internal registers
	twiwrite(data);
	twistop();					//STOP
}