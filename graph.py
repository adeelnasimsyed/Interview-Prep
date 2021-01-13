from collections import defaultdict

class Graph():

	def __init__(self):

		self.graph = defaultdict(set)

	def addConnection(self, u, v):

		if u not in self.graph[v]:

			self.graph[v].add(u)
			self.graph[u].add(v)

	def addNode(self, u):

		if u not in self.graph:

			self.graph[u] = {}

	def BFS(self, start):

		visited = [False] * (max(self.graph) + 1)

		deque = []

		deque.append(start)
		visited[start] = True

		while deque:

			node = deque.pop(0)
			print(node, end = " ")

			for conns in self.graph[node]:

				if visited[conns] == False:
					deque.append(conns)
					visited[conns] = True


	def DFSUtil(self, node, visited):
			
		visited.add(node)
		print(node, end = " ")

		for conn in self.graph[node]:

			if conn not in visited:

				self.DFSUtil(conn, visited)


	def DFS(self, start):

		visited = set()
		self.DFSUtil(start, visited)
		

	def __str__(self):

		return(str(self.graph))

g = Graph()


g.addConnection(0,1)
g.addConnection(0,2)
g.addConnection(1,2)
g.addConnection(2,0)
g.addConnection(2,3)
g.addConnection(3,3)
g.addConnection(3,5)
g.addConnection(2,5)
g.addConnection(1,6)
g.addConnection(6,8)
g.addConnection(6,9)
g.BFS(2)
print(g)
g.DFS(2)

