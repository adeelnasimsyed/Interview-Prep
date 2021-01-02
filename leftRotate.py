
# Function to exchange data of two given indices in a list
def swap(A, i, j):
 
    data = A[i]
    A[i] = A[j]
    A[j] = data
 
 
# Function to reverse a given sublist
def reverse(A, low, high):
 
    (i, j) = (low, high)
    while i < j:
        swap(A, i, j)
        i = i + 1
        j = j - 1
 
 
# Function to left rotate a list by r positions
def leftRotate(A, r):
 
    # Reverse the first 'r' elements
    reverse(A, 0, r - 1)
 
    # Reverse the remaining 'n-r' elements
    reverse(A, r, len(A) - 1)
 
    # Reverse the whole list
    reverse(A, 0, len(A) - 1)
 
 
if __name__ == '__main__':
 
    A = [1, 2, 3, 4, 5]
    r = 2
 
    leftRotate(A, r)
    print(A)
 