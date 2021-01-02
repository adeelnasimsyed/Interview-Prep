def countOddZeroes(arr):

  oddCount = 0

  for num in arr:
    zeroCount = 0

    while(num):

      if num % 10 == 0:
        zeroCount += 1
      
      num = num // 10
    
    if zeroCount % 2 == 1:
      oddCount += 1
  

  return oddCount


array = [100, 7000, 80111]
print(countOddZeroes(array))
