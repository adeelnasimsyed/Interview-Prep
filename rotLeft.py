'''
A left rotation operation on an array shifts each of the array's elements 1 unit to the left. 
For example, if 2 left rotations are performed on array [1,2,3,4,5] ,
then the array would become [3,4,5,1,2].
Note that the lowest index item moves to the highest index in a rotation.
This is called a circular array.

Given an array a of n integers and a number, d ,perform left rotations on the array.
Return the updated array to be printed as a single line of space-separated integers.
'''
from typing import List



def rotLeft(a: List[int], d: int) -> List[int]:
	
	n = len(a)
	if d == n:
		return a
	
	tempArr = a[:d]
	a = a[d:]
	a += tempArr
	
	return a

def swap(arr, i, j):

	temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp

	return arr

def reverse(A, low, high):

	while low < high:
		A = swap(A, low, high)
		low += 1
		high -+ 1

	return A

def leftRotate(a: List[int], d: int) -> List[int]:

	# Reverse the first 'd' elements
	a = reverse(a, 0, d - 1)
 
    # Reverse the remaining 'n-d' elements
	a = reverse(a, d, len(a) - 1)
 
    # Reverse the whole list
	a = reverse(a, 0, len(a) - 1)

	return a




a = [1,2,3,4,5]
d = 2 
print(rotLeft(a, d)) 

print(leftRotate(a, d)) 