import sys
s = sys.stdin.readline()
# pre-compute
sums = [0]*len(s)
for i in range(1,len(s)):
    sums[i]=sums[i-1]+(s[i] == s[i-1])

for t in range(int(sys.stdin.readline())):
    l,r = map(int, sys.stdin.readline().split())
    print(sums[r-1]-sums[l-1])
