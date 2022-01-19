#include <stdio.h>

float myfabs(float input)
{
	union 
	{
		unsigned int i;
		float f;
	} U = { .f = input};

	
	U.i &= ~(0x80000000);


	return U.f;

}

int main()
{
	float f = -1.2;

	printf("%f\n", myfabs(f));
	return 0;
}