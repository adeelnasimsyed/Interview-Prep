#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef union
{
	float f;
	uint32_t i;

}NumberConversionT;

void sendTCPfloat(char buffer[])
{
	NumberConversionT ReceivedLS;

	ReceivedLS.i = buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3];
	float test = ReceivedLS.f;

	printf("%f\n", ReceivedLS.f);

	return;
}

void main(void)
{
	NumberConversionT LineSpeed;
	char buffer[4];


	LineSpeed.f = 1.5;
	float check = LineSpeed.f;

	buffer[0] = (LineSpeed.i >> 24) & 0xFF;
	buffer[1] = (LineSpeed.i >> 16) & 0xFF;
	buffer[2] = (LineSpeed.i >> 8) & 0xFF;
	buffer[3] = LineSpeed.i & 0xFF;

	
	printf("%f\n", check);

	sendTCPfloat(buffer);
	return;
}