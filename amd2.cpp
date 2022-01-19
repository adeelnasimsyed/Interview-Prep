/* func to take 32 bit input and outputs 32bit, maps input to the output where every single
bit in input is masked to 2 bits in the output

example

input = 1 (001)
output = 3 (011)

input = 2 (010)
output = C (1100)

input = 5 (101)
output = x33 (0011 0011)


input = 4 (011)
output =  (1111)

*/


int Func (int input)
{	
	int idx = 0;
	int output = 0;
	input = input & 0xFFFF;

	while(input)
	{
		if(input & 0x1)
		{
			output |= 1<<idx;
			output |= 1<<idx+1;
		}

		idx+= 2;
		input >>= 1;
	}


	return output;
}

int main()
{
	return 0;
}