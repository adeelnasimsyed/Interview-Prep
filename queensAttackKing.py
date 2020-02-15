#checks if queens can attack a king, queens can move in 8 directions and cannot jump over others
def queensAttackKing(queens, king):
	kingX = king[0]
	kingY = king[1]
	attackingQueens = []
	directions = [[1,0], [0,1], [-1,0], [0,-1], [1,1], [-1,1], [1,-1], [-1,-1]]


	chessboard = [[False for i in range(8)] for j in range(8)]
	
	
	chessboard[kingX][kingY] = True

	for queenX, queenY in queens:

		chessboard[queenX][queenY] = True
	

	for dx, dy in directions:

		moveKing_X = kingX
		moveKing_Y = kingY

		while(moveKing_X >= 0 and moveKing_X < 8 and moveKing_Y >= 0 and moveKing_Y < 8):

			moveKing_X += dx
			moveKing_Y += dy

			if(chessboard[moveKing_X][moveKing_Y]):

				attackingQueens.append([moveKing_X,moveKing_Y])
				break

	return attackingQueens


queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]
king = [0,0]

print(queensAttackKing(queens, king))
