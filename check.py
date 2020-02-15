# from graph import Graph

# connections = [(1, 2), (2, 3), (2, 4),(3, 4), (5, 6), (6, 3)]

# g = Graph(connections = connections, directed = False)
# # g.add(5,6)
# print(g._graph) 

# from collections import defaultdict

# def fruitBasket(arr):

# 	basket = defaultdict(int)



def longestPalindrome(word):

	length = len(word)
	max_length = 1
	start = 0

	
	for i in range(1, length):

		left = i - 1
		right = i
		
		# even length words
		while(left >= 0 and right < length and word[left] == word[right]):


			if(right - left + 1 > max_length):

				start = left

				max_length = right - left + 1


			left -= 1
			right += 1

		left = i - 1
		right = i + 1
		# odd length words
		while(left >= 0 and right < length and word[left] == word[right]):


			if(right - left + 1 > max_length):

				start = left

				max_length = right - left + 1


			left -= 1
			right += 1


	return word[start:start+max_length]



word = "aaaabasldkajsaldjaslkdjasldjka"
print(longestPalindrome(word))