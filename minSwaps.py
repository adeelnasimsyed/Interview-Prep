'''
Min swaps required to sort an array into ascending order

arr = [3,1,4,2]
copyArr = [1,2,3,4]

hashMap = 1: 0
		  2: 1
		  3: 2
		  4: 3

'''


arr = [3,4,2,1,5]
swaps = 0

hM = {}
cp_arr = arr.copy()
cp_arr.sort()

for i in range(len(arr)):
	hM[arr[i]] = i
	'''
	cp_arr[1,2,3,4,5]
	hM[1] = 0
	h[2] = 1
	.
	.
	.
	'''
	
print(hM)
for i in range(len(arr)):

	if arr[i] != cp_arr[i]:
		swaps += 1
		correctEle = arr[i]
		
		arr[i], arr[hM[cp_arr[i]]] = arr[hM[cp_arr[i]]], arr[i]
		hM[correctEle] = hM[cp_arr[i]]
		hM[cp_arr[i]] = i 
		



print(arr)
print(swaps)

'''
made a hashmap of the indexes of the unsorted array
for each array element, look up the index of correct element that SHOULD be in that position
then swap

update hash map with new indexes of both swapped elements 
'''