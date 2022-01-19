#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int kSmallestNum(int *arr, int size, int k)
{
	sort(arr, arr + size);

	return arr[k-1];
}

void printArr(int *arr, int size)
{
	int first = 1;

	cout << "[";
	for(int i = 0; i < size; i++)
	{
		if (first)
			first = 0;
		else
			cout << ", ";
		cout << arr[i];
	}

	cout << "]\n";
}

int main()
{
	int A[10] = {1,22,55,18, 99,43,2,58,76,100};

	cout << kSmallestNum(A, 10, 2) << endl;
	printArr(A, 10);

	return 0;
}