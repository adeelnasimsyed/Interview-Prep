'''
two sum problem

'''

def whatFlavour(cost, money):

	hM = dict()

	for idx, val in enumerate(cost):

		if val in hM:

			hM[val].append(idx+1)

		else:

			hM[val] = [idx+1]

	print(hM)

	for idx, val in enumerate(cost):

		if (money-val) in hM and (idx+1) != hM[money-val][0]:

			if (money - val) != val:
				ans = '{} {}'.format(min(hM[money-val][0], hM[val][0]), max(hM[money-val][0], hM[val][0]))
			else:
				ans = '{} {}'.format(hM[val][0], hM[val][1])

			print(ans)
			return
	


cost = [2, 2, 3, 5]
cost1 = [4, 3, 2, 5, 7]
cost2 = [7,2,5,4,11]
whatFlavour(cost2,12)