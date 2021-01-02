'''
In a string check how many deletions are needed so that there are only alternating As and Bs
'''

def alternatingChars(s):

	deletions = 0

	for i in range(len(s) - 1):

		j = i + 1

		if s[i] == s[j]:

			deletions += 1

	return deletions


print(alternatingChars('AAABBB'))