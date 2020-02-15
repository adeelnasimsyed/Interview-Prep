#returns the k smallest num in array
def kSmallestNum(array, k):

	array.sort()

	if k > len(array):

		return array[-1]

	else:
		return array[k-1]


array = [1,10,2,9,22,3,4]
print(kSmallestNum(array,3))
