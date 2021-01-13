// given an array of expense, and days d, check if expense[i] >= 2x median 
//of expense[i-d] to expense[i-1]


//using qsort everytime was causing time out, use count sort


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int median(int count[], int count_size, int d)
{
	int countFreq[count_size];
	int first = 0, second = 0;
	int m1 = 0, m2 = 0;
	int i = 0;

	memcpy(countFreq, count, sizeof(int) * count_size);

	for(i = 1; i < 201; i++)
	{
		countFreq[i] += countFreq[i-1];
	}



	// qsort(array, size, sizeof(int), compare);

	//even
	if (d % 2 == 0)
	{
		first = d/2;
		second = first + 1;

		for(i = 0; i < 201; i++)
		{
			if(first <= countFreq[i])
			{
				m1 = i;
				break;
			}
		}

		for(i = 0; i < 201; i++)
		{
			if(second <= countFreq[i])
			{
				m2 = i;
				break;
			}
		}

		return m1 + m2;
	}

	//odd
	else
	{
		first = d/2 + 1;

		for(i = 0; i < 201; i++)
		{
			if(first <= countFreq[i])
			{
				m1 = i;
				break;
			}
		}


		return 2 * m1;
	}
}

void main(void)
{
	int d = 5;
	int a[] = {2,3,4,2,3,6,8,4,5};
	// int a[] = {1,2,3,4,4};
 	int a_count = sizeof(a)/sizeof(a[0]);
	int i = 0, notify = 0;
	int m = 0;
	int j = 0;

	int count[201] = {};
	int count_size = sizeof(count)/sizeof(int);

	//make the count array
	for(i = 0; i < d; i++)
	{
		count[a[i]]++;
	}

	for(i = d; i < a_count; i++)
	{
		
		// memcpy(prev_array, a + (i - d), sizeof(int) * d);
		m = median(count, count_size, d);
		
		if (a[i] >= m)
		{
			notify++;
		}

		count[a[i]]++;
		count[a[i-d]]--;

	}

	printf("%d\n", notify);

	return;
} 