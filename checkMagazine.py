'''
Check an array of strings if another string is a subset (case senstive)

magazine = "Attack at down"
note = "attack at down"


return false

'''

def checkMagazine(magazine, note):

	hM = {}

	for word in magazine.split():

		if word in hM:
			hM[word] += 1
		else:
			hM[word] = 1

	for word in note.split():

		if word in hM:
			hM[word] -= 1

			if hM[word] == 0:

				del hM[word]

		else:
			print("No")
			return

	print("Yes")
	return


magazine = "ive got a lovely bunch of coconuts"
note = "ive got coconuts"
checkMagazine(magazine, note)