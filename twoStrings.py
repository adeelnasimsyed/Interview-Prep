'''
check if string1 has any substring match with string2

method:

decompose string1 in ALL possible substrings and store in hashMap

then decompose string2 in ALL substrings and check if available in hashMap
'''


def twoStrings(s1, s2):

	hM = {}

	for i in range(len(s1)):
		for j in range(i+1, len(s1)+1):

			subStr = s1[i:j]

			if subStr in hM:
				hM[subStr] += 1
			else:
				hM[subStr] = 1


	for i in range(len(s2)):
		for j in range(i+1, len(s2) + 1):

			subStr = s2[i:j]

			if subStr in hM:

				print("Yes")
				print(subStr)
				return

	print("No")
	return





s1 = "hello"
s2 = "wrd"

twoStrings(s1, s2)