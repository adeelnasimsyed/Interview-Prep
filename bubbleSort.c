// do bubble sort and print number of swaps


#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void count_swap(int a_count, int *a)
{
	int i = 0, j = 0, numSwap = 0;;

	for(i = 0; i < a_count - 1; i++)
	{
		for(j = i+1; j < a_count; j++)
		{
			if (a[j] < a[i])
			{
				swap(&a[j], &a[i]);
				numSwap++;
			}
		}
	
	}

	printf("%d\n", numSwap);
	printf("%d\n", a[0]);
	printf("%d\n", a[a_count-1]);
}

void check(int *num1, int *num2)
{
	*num1 = 10;
	*num2 = 20;
}

int check1(int a, int b);

void main(void)
{

/*	int a[20] = {6,4,1};
	int i = 0;
	for(i = 0; i < 20; i++)
		printf("%d\n", a[i]);*/

	
	printf("%d\n",check1(1,2));

/*	int a_count = sizeof(a)/sizeof(a[0]);

	count_swap(a_count, a);*/
}

int check1(int num1, int num2)
{
	return num1 + num2;
}