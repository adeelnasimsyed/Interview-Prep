'''
find pair of nums in an array whose diff equals target
'''

def pairs(arr, target):
	
	hM = dict()

	for num in arr:

		if num+target in hM:
			hM[num+target] += 1

		else:

			hM[num+target] = 1

	count = 0
	for num in arr:

		if num in hM:
			count += 1

	print(count)


a = [1,2,3,4]
b = [1,5,3,4,2]
target = 2

pairs(b, target)