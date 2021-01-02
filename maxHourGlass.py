'''
Given a 6x6 2D Array, arr:

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

An hourglass in  is a subset of values with indices falling 
in this pattern in 's graphical representation:

a b c
  d
e f g

There are 16 hourglasses in arr. An hourglass sum is the sum of an 
hourglass' values. Calculate the hourglass sum for every hourglass in arr,
then print the maximum hourglass sum. The array will always be 6x6.
'''
from typing import List

def maxHourGlass(arr: List[List[int]]) -> int:

	maxSum = 0
	
	for i in range(0, len(arr)):
		for j in range(0, len(arr[0])):

			newSum = 0

			if( j != 0 and j != 5 and i <= 3):

				newSum = arr[i][j-1] + arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+2][j-1] + arr[i+2][j] + arr[i+2][j+1]

				if newSum > maxSum:
					maxSum = newSum

	return maxSum


arr = \
[[1, 1, 1, 0, 0, 0],
[0, 1, 0, 0, 0, 0],
[1, 1, 1, 0, 0, 0],
[0, 0, 2, 4, 4, 0],
[0, 0, 0, 2, 0, 0],
[0, 0, 1, 2, 4, 0]]

arr2 = \
[[-9, -9,-9,  1, 1, 1],
[0, -9,  0,  4, 3, 2],
[-9, -9, -9,  1, 2, 3],
[ 0,  0,  8,  6, 6, 0],
[ 0,  0,  0, -2, 0, 0],
[0,  0,  1,  2, 4, 0]]

print(maxHourGlass(arr2))