
#include <stdarg.h>

void myPrintf(char *message, ...)
{
	unsigned int i;
	va_list arg; 
	va_start(arg, message);

	while (*message != '%')
	{

		putchar(*message);
		message++;
	}

	message++;

	switch(*message)
	{
		case 'd':
			i = va_arg(arg, int);
			puts(i);
			break;

		default:
			break;

	}

	printf("reached here\n");
	return;
}


void main(void)
{

	myPrintf("my hello world! %d\n");

}