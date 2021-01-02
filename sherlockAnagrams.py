'''
in a string count the number of anagrams. 



 method:
 find all substrings and make a hash map of sorted substring
 All enteries that have values > 2 then add values

'''

from collections import defaultdict

def sherlockAnagram(word):

	hM = defaultdict(int)

	for i in range(len(word)):

		sub = ''

		for j in range(i, len(word)):

			sub = ''.join(sorted(sub + word[j]))
			hM[sub] += 1

	ans = 0

	for k,v in hM.items():

		ans += (v * (v-1))//2

	return ans


print(sherlockAnagram("cdcd"))

