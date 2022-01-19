#include <stdio.h>
#include <string.h>

void reverseString(char *s, int start, int end)
{
	char temp;
/*	char *start = s;
	char *end = start + strlen(s) - 1;*/

	while(start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}

}

int main()
{
	char check[] = "Hello World";
	reverseString(check, 6, 10);

	printf("%s\n", check);
	return 0;
}