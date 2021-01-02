'''
In an array check how many triplets exist of a common ration R

example:

ratio: 4
[1,4,16,64]

triplets:
[1,4,16] and [4,16,64]

returns 2

method:

read array in reverse order
have two dicts, one for each number and one for each pair that meet criteria

if a num*ratio exists in dic that means we have a pair

if num*ratio exists in dicPair that means we have num, and the pair in dicPair

'''


def countTriplets(arr, ratio):

	dic = {}
	dicPairs = {}
	count = 0

	for num in reversed(arr):

		if num*ratio in dicPairs:

			count += dicPairs[num*ratio]

		if num*ratio in dic:

			dicPairs[num] = dicPairs.get(num, 0) + dic[num*ratio]


		dic[num] = dic.get(num, 0) + 1


	print(count)
	
arr = [1, 5, 5, 25, 125]

countTriplets(arr, 5)
