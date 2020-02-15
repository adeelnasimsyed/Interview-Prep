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
