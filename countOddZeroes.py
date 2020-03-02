def countOddZeroes(arr):

  count = 0

  for num in arr:
    numCount = 0

    while(num):

      if num % 10 == 0:
        numCount += 1
      
      num = num // 10
    
    if numCount % 2 == 1:
      count += 1
  

  return count


array = [100, 7000, 80111]
print(countOddZeroes(array))
