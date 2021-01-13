from collections import defaultdict

#returns the first k most frequent words in a string(same frequency ordered alphabetically)
def frequentWords(words, k):

	d = defaultdict(int)

	for word in words.split(" "):
		word = word.lower().strip(",!_+=-@")

		d[word] += 1

	for v in sorted(d.items(), key = lambda kv: (-kv[1], kv[0])):
		print(v)
	
	output = [v[0] for v in sorted(d.items(), key = lambda kv: (-kv[1], kv[0]), reverse=False)]

	print(output)
	print(output[:k])


a = "apple apple apple azdy azdy azdy Gabba gabba hey, gabba gabba hey!"

frequentWords(a,2)

