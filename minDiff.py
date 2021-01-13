'''
given an array find the min absolute difference between any two nums

'''


def minDiff(arr):

	hM = dict()

	for num in arr:

		if num in hM:

			hM[num] += 1
		else:
			hM[num] = 1



a = [1,4,5,6,7,28,9]

minDiff(a)

num1 = 3
num2 = 5
rangeEnd = 1000
s = 0

for i in range(rangeEnd):


	if i%num1 == 0 or i%num2 == 0:
		
		s+= i


print(s)
