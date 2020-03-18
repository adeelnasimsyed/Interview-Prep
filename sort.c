#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define sleep(x) Sleep(1000 * (x))

void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

int * bubbleSort(int arr[], int size){

	int i = 0, j = 0;
	for(i = 0; i < size; ++i){
		for(j = 0; j < size - 1; ++j){
			
			if(arr[j] > arr[j+1]){

				swap(&arr[j], &arr[j+1]);
			}
		}
	}

	printf("\n");

	return (int*)arr;
}

void merge(int arr[], int left, int middle, int right){
	int size_left = middle - left + 1;
	int size_right = right - middle;

	int tempLeft[size_left], tempRight[size_right];
	int i, j, k;

	for(i = 0; i < size_left; ++i){

		tempLeft[i] = arr[left + i];
	}

	for(i = 0; i < size_right; ++i){

		tempRight[i] = arr[middle + 1+ i];
	}

	i = 0;
	j = 0;
	k = left;

	while(i < size_left && j < size_right){

		if(tempLeft[i] <= tempRight[j]){

			arr[k] = tempLeft[i];
			i++;
		}
		
		else{

			arr[k] = tempRight[j];
			j++;
		}

		k++;

	}

	while(i < size_left){

		arr[k] = tempLeft[i];
		i++;
		k++;
	} 

	while(j < size_right){

		arr[k] = tempRight[j];
		j++;
		k++;
	}   
}

void mergeSort(int arr[], int left, int right){



	if (left < right){

		int middle = (left + right) /2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle+1, right);
	
		merge(arr,left, middle, right);
	}
}


int partition(int arr[], int low, int high){

	int pivot = arr[high];
	int i = low - 1;
	int j;

	for(j = low; j < high; j++){

		if(arr[j] < pivot){

			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high){

	if (low < high){

		int pi = partition(arr,low,high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}

}

int * insertionSort(int arr[], int size){

	int i, j, key;

	for(i = 1; i < size; i++){

		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key){

			arr[j+1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}

	return (int*)arr;
}

void reverseString(char string[], int length){

	char *start = string;
	char *end = start + length - 1;
	char temp;

	while(start < end){

		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;

	}

}

void main(){

	int array[] = {1,99,8,22, 2, 10};
	double timeElapsed = 0.0;

	int size = sizeof(array) / sizeof(int);

	// time_t begin = time(NULL);

	// int *sorted_arr = bubbleSort(array, size);
	// sleep(1);
	// time_t end = time(NULL);

	// timeElapsed = (double)(end - begin);

	// int i;
	//mergeSort(array, 0, size - 1);

	//quickSort(array, 0, size - 1);

	// int *sorted_arr = insertionSort(array, size);

	// for(i = 0; i < size; ++i){

	// 	printf("%d ", array[i]);
	
	// char s1[] = "hello";
	// reverseString(s1, 5);
	// printf("%s\n", s1);


	const volatile int local = 10; 
	int *ptr = (int*) &local; 
	printf("Initial value of local : %d \n", local); 
	*ptr = 100; 
	printf("Modified value of local: %d \n", local); 
 



	}


	// printf("\nTime Elapsed = %f \n", timeElapsed);


