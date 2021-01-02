'''
input queries in the format:

q = [[1,2],
     [1,8],
     [2,2],
     [3,1]]

     where q[row][0]:
     1: add q[row][1] to a data structure, or increase freq if already there
     2: remove q[row][1] from data structure, or decrease freq if there
     3: check if q[row][1] is present in data strcuture.values() 

 method:
 to not have run time error have two data structures, one tracks the nums and one the freqs

'''
from collections import defaultdict

def freqQueries(queries):

	hM_val = defaultdict(int)
	hM_freq = defaultdict(int)
	ans = []

	for operation, num in queries:

		if operation == 1:

			if num in hM_val:
				freq = hM_val[num]
				hM_freq[freq] -= 1

				if hM_freq[freq] == 0:
					del hM_freq[freq]

				hM_val[num] +=1
				hM_freq[freq+1] += 1

			else:
				freq = 1
				hM_val[num] +=1
				hM_freq[freq] += 1

		if operation == 2:

			if num in hM_val:

				freq = hM_val[num]

				if freq == 1:
					del hM_val[num]

					if hM_freq[freq] == 1:
						del hM_freq[freq]
					else:
						hM_freq[freq] -= 1

				else:
					hM_val[num] -= 1
					hM_freq[freq] -= 1
					hM_freq[freq -1] +=1

					if hM_freq[freq] == 0:
						del hM_freq[freq]

		if operation == 3:

			if num in hM_freq:

				ans.append(1)

			else:
				ans.append(0)

	return ans


queries = \
[[1,5],
[1, 6],
[3, 2],
[1, 10],
[1, 10],
[1, 6],
[2, 5],
[3, 2]]

print(freqQueries(queries))


