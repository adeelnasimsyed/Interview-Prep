'''
given two strings make them anagrams by performing deletions on both, return number of deletions

'''

def makeAnagram(s1, s2):

	hM = dict()
	deletes = 0

	for char in s1:

		if char in hM:
			hM[char] += 1
		else:
			hM[char] = 1

	for char in s2:

		if char in hM:
			hM[char] -= 1
		else:
			hM[char] = -1 

	for k,v in hM.items():
		
		deletes += abs(v)

	return deletes


s1 = 'abccd'
s2 = 'cde'

print(makeAnagram(s1, s2))