//implement merge sort
#include <stdio.h>

void merge(int arr[], int left, int middle, int right, int* var)
{
	int leftSize = middle - left + 1;
	int rightSize = right - middle;

	int tempLeft[leftSize];
	int tempRight[rightSize];
	int i, j, k;

	for(i = 0; i < leftSize; i++)
	{
		tempLeft[i] = arr[left + i];
	}

	for(i = 0; i < rightSize; i++)
	{
		tempRight[i] = arr[middle + i + 1];
	}

	i = 0;
	j = 0;
	k = left;

	while(i < leftSize && j < rightSize)
	{
		if(tempLeft[i] <= tempRight[j])
		{
			arr[k] = tempLeft[i];
			i++;
			(*var)++;

		}

		else
		{
			arr[k] = tempRight[j];
			j++;
			(*var)++;
		}

		k++;
	}

	while(i < leftSize)
	{
		arr[k] = tempLeft[i];
		i++;
		k++;
	}

	while(j < rightSize)
	{
		arr[k] = tempRight[j];
		j++;
		k++;
	}

}

void mergeSort(int arr[], int left, int right, int*var)
{

	if (left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(arr, left, middle, var);
		mergeSort(arr, middle + 1, right, var);

		merge(arr, left, middle, right, var);	
	}

}

void printArr(int arr[], int arrSize)
{
	int i;
	printf("[");
	for(i = 0; i < arrSize; i++)
	{
		if (i < arrSize - 1)
		{
			printf("%d, ", arr[i]);
		}

		else
		{
			printf("%d", arr[i]);
		}
		
	}
	printf("]\n");

	return;
}

void main(void)
{
	int swaps = 0;
	int *swapPtr = &swaps;

	int a[] = {6,4,1};
	int a_count = sizeof(a)/sizeof(a[0]);

	mergeSort(a, 0, a_count - 1, swapPtr);

	printArr(a, a_count);

	printf("The number of swaps: %d\n", swaps);


}