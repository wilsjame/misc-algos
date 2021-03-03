import math
n = int(input())
# 1 positions
# 0 1 3 6 10 15 21 28
#  1 2 3 4  5  6  7
# n = (block*(block+1))/2
block = (1/2)*(math.sqrt(8*n-1)-1)
block = math.floor(block)
print(n - (block*(block+1))//2)
