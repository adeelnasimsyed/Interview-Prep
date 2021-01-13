// given an array of prices and a currency number find out how many toys you can buy


#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

void main(void)
{

	int a[] = {1, 12, 5, 111, 200, 1000, 10};
	int budget = 50;
	int a_count = sizeof(a)/sizeof(a[0]);
	int i = 0, j = 0;

	qsort(a, a_count, sizeof(int), compare);

	while(budget > 0 && i < a_count)
	{
		budget -= a[i];
		i++;
	}

	for(j = 0; j < i - 1; j++)
	{
		printf("%d\n", a[j]);
	}

}
