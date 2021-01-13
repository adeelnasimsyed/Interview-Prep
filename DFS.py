'''
find biggest region of connected 1's in a grid of 1s and 0s

''' 
def isSafe(grid, row, col, visited):

	if (row < 0) or (row >= ROWS) or (col < 0) or (col >= COLS) \
		or (grid[row][col] == 0) or (visited[row][col] == 1):

		return False

	else:
		return True	

def DFS(grid, row, col, count, visited):

	global ROWS, COLS

	neighbours = [[-1,0], [-1,-1], [-1,1], [0,1],[0,-1],[1,-1],[1,0],[1,1]]

	visited[row][col] = 1

	for dx, dy in neighbours:

		if isSafe(grid, row+dx, col+dy, visited):

			count[0] += 1 

			DFS(grid, row+dx, col+dy, count, visited)


def largestRegion(grid):

	global ROWS, COLS

	result = 0

	visited = [[0] * COLS for i in range(ROWS)]

	for i in range(ROWS):
		for j in range(COLS):

			if grid[i][j] == 1 and not visited[i][j]:

				count = [1]

				DFS(grid, i, j, count, visited)

				result = max(result, count[0])

	return result


grid = [[0, 0, 1, 1, 0],
     [1, 0, 1, 1, 0],
     [0, 1, 0, 0, 0],
     [0, 0, 0, 0, 1]]

ROWS = len(grid)
COLS = len(grid[0])


print(largestRegion(grid))