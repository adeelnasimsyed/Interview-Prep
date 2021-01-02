'''
Given a set of points find the min time needed to reach each point

Rules:
1. Can only go to consecutive points
2. Can transverse one pos in x, one in y OR one in both x and y
'''
from typing import List

def minTimeVisit(points: List[List[int]]) -> int:
	
	totalSteps = 0
	j = 0
	for i in range(0, len(points)):
		
		j = i + 1

		if (j >= len(points)):
			break
		
		x_diff = abs(points[i][0] - points[j][0])
		y_diff = abs(points[i][1] - points[j][1])

		totalSteps += min(x_diff,y_diff)
		totalSteps += abs(x_diff - y_diff)
		
	return totalSteps

points = [[1,1],[3,4],[-1,0]]

print(minTimeVisit(points))