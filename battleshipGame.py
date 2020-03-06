from collections import defaultdict

def battleshipGame(board, moves):

  directions = [[1,0] , [0,1]]
  d = defaultdict(list)
  ship = 0
  shipFound = False

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

  for k, v in d.items():

    print(k, v)
