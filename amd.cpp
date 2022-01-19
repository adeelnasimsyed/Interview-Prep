#include <iostream>

using namespace std;
volatile int i;

bool superFlip(bool input)
{
	static int output = 0;
	static int prevInput = 0;

	if (input == 1)
	{
		output = 1
		
	}

	else if(input == 1 && prevInput == 1)
	{
		output = 0;
	}

	prevInput = input;
	return output;
}


int main()
{
	return 0;
}