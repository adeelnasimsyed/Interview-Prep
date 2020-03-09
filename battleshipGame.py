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
  nextMove = False
  miss = True
  for move_x, move_y in moves:
    nextMove = False
    for k, v in d.items():
      miss = False
      for x,y in v:

        if x != move_x and y != move_y:
          miss = True
        
        elif x == move_x and y == move_y:
          if len(v) == 1 and len(d) > 1:
            print("Dead")
            output.append("Dead")
            del d[k]
            nextMove = True
            break
          if len(v) == 1 and len(d) == 1:
            output.append("Game Over")
            nextMove = True
            break
          else:
            print("Hit")
            output.append("Hit")
            nextMove = True
            break
      
      if nextMove:
        break
      if miss:
        output.append("Miss")



  return output



board = [[".", ".","#","#"], 
[".", ".","#","#"],
["#", ".",".","."],
[".", ".",".","."]]
moves = [[1,0], [0,3], [1,3]]
battleshipGame(board, moves)

