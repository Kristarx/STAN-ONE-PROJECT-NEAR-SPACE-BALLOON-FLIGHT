
/*
first part

initialization variables, fill napis string with ""


second part

create oe string from
various data and save them
on the SD card */



uint8_t napis[128];
int SD_Licznik = 0;
int counter = 0;

for(int i = 0; i < 128; i++)
{
	napis[i] = "";
}



//*********************************************************************



char buff[100];
sprintf(buff, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", buffer, " ", AX, " ", AY, " ", AZ, " ", TEMP, " ", PRES, " ", ALT, " ", WILG, " ", TEMPERATURE, " ", TEMPERATURE_IN, " ", LUX);

for(int i = 0; i < 100; i++)
{
	napis[i] = buff[i];
}


pf_write( napis,strlen((const char *)napis), &w);
pf_lseek(512*(SD_Licznik+1));
pf_write(0, 0, &w);
SD_Licznik++;
counter++;