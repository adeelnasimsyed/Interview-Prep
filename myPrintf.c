
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char *convertInt(unsigned int i)
{
	char *ptr;

	static char Numbers[] = "0123456789";

	static char buffer[10];

	ptr = &buffer[9];
	*ptr = '\0';

	while(i)
	{	
		ptr--;
		*ptr = Numbers[i % 10];
		i /= 10;
		
	}

	return ptr;
}

void myPrintf(char *message, ...)
{
	unsigned int i;
	char * traverse;
	int idx = 0;
	float f;
	va_list arg; 
	va_start(arg, message);

	for (traverse = message; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%')
		{

			putchar(*traverse);
			traverse++;
		}

		traverse++;

		switch(*traverse)
		{
			case 'd':
				i = va_arg(arg, int);

				if (i < 0)
				{
					putchar('-');
				}

				puts(convertInt(i));			
				break;

		}
		

	}

	va_end(arg);
	return;
}


void main(void)
{

	myPrintf("my hello world! %d", 22);

}