def reverseAdd(arr):
  endZeroes = 0
  temp = ""
  total = 0

  for num in arr:
    endZeroes = 0
    tempNum = num

    while(tempNum % 10 == 0):
      endZeroes += 1
      tempNum /= 10

    temp = str(num)
    temp = temp[::-1]
  
    temp = int(temp)

    while(endZeroes):
      temp *= 10
      endZeroes -= 1
    
    total += temp
  
  return total


array = [100, 123, 7100]
print(reverseAdd(array))
