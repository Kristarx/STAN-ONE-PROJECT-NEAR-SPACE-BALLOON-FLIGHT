
/*function the aim is
get temperature and convert 
it to string. The format of temperature
is XX,X
*/



if(ds18b20_ConvertT_wewn())
{
	_delay_ms(100);
	ds18b20_Read_wewn(ds18b20_pad_in);
	temp = ((ds18b20_pad_in[1] << 8) + ds18b20_pad_in[0]) / 16.0 ;
	tem1 = temp;
	tem2 = abs((temp - tem1)*10);
}

sprintf(TEMPERATURE_IN,"%d.%d", tem1, tem2);