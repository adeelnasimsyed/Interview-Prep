from collections import defaultdict

def battleshipGame(board, moves):

  directions = [[1,0] , [0,1]]
  d = defaultdict(list)
  ship = 0
  shipFound = False
  output = []

  for i in range(len(board)):
    for j in range(len(board[0])):

      if board[i][j] == "#":
        d[ship].append([i,j])
        board[i][j] = "." 
        shipFound = False

        for dx, dy in directions:
          
          x = i
          y = j

          while(x+dx < len(board) and y + dy < len(board[0])):

            x += dx
            y += dy
            
            if board[x][y] == "#":
              d[ship].append([x,y])
              board[x][y] = "." 
              shipFound = True
            else:
              break
          
          
          if shipFound:
            break
        ship += 1

  for move in moves:

    miss = True

    for values in d.values():

      if move in values:
        
        if len(values) == 1:
          
          if len(d) == 1:
            output.append("Game Over")
            return output
          
          else:
            output.append("Dead")

            miss = False
            break
        else:
          values.remove(move)
          output.append("Hit")
          miss = False
          break

    if miss:
      output.append("Miss")

  return output



board = [[".", ".","#","#"], 
[".", ".","#","#"],
["#", ".",".","."],
[".", ".",".","."]]
moves = [[1,0], [0,3], [1,3]]
print(battleshipGame(board, moves))

