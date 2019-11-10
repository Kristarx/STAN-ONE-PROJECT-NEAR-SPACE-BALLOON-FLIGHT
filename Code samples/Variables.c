
/*definiton of some variables,
I2C communication
and RTC DS 3231 registers
*/

#define ACK 1
#define NOACK 0

#define ds3231_adr 0b11010000		//base address for DS3231 RTC
#define ds3231_REG_TIME             0x00
#define ds3231_REG_ALARM_1          0x07
#define ds3231_REG_ALARM_2          0x0B
#define ds3231_REG_CONTROL          0x0E
#define ds3231_REG_STATUS           0x0F
#define ds3231_REG_TEMPERATURE		0x11

void twi_clock_setting(uint16_t clk_KHz); //function for setting frequency of clock signal (SCL)
void twistart(void);				//function for transmit START
void twistop(void);					//function for transmit STOP
void twiwrite(char data);			//function for writing DATA
char twiread(char ack);				//function for reading DATA

void twiwrite_buf( uint8_t SLA, uint8_t adr, uint8_t len, uint8_t *buf );	//function for writing buffer
void twiread_buf(uint8_t SLA, uint8_t adr, uint8_t len, uint8_t *buf);		//function for reading buffer

uint8_t dec2bcd(uint8_t d);			//DEC to BCD
uint8_t bcd2dec(uint8_t b);			//BCD to DEC

void twiread_ds3231(void);				//function for reading from ds3231 RTC
void twiwrite_ds3231(uint8_t register_adr, uint8_t data);			//function for writing to ds3231 RTC
void write_control_register(uint8_t control);		//function for setting Control Register (address=0x0E)

char buffer[16];					//buffer for LCD

uint8_t wr_ds3231_buf[19], rd_ds3231_buf[19];
uint8_t seconds=0, minutes=0, hours=0, years=0;
uint8_t temp0=0, temp1=0, temp2=0;