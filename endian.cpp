#include <cstdio>
#include <cstdlib>
#include <stdint.h>

int is_big_endian(void)
{
	union
	{	
		uint32_t i;
		char c[4];
	} e = {0x01000000};


	return e.c[0];
}


int main(void)
{

	printf("The system is %s-endian\n", is_big_endian()? "big" : "little" );
}