from collections import defaultdict

def eraseOneDigit(firstNum, secondNum, thirdNum):

	d = defaultdict(int)
	target = str(int(thirdNum) - int(secondNum))

	for char in firstNum:
		d[char] += 1

	for char in target:

		d[char] -=1
		if d[char] == 0:
			del d[char]

	if len(d) > 1:
		return False

	return True	




firstNum = "167"
secondNum = "33"
thirdNum = "100"

print(eraseOneDigit(firstNum, secondNum, thirdNum))