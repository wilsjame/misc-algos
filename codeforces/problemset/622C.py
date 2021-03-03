import sys
n, m = map(int, input().split()) 
a = list(map(int, input().split()))
# merge cells when a[i] == a[i+1] so we can make jumps when searching
# 1 2 1 1 3 5 - a
# 1 2 4 4 5 6 - nxt
nxt = [0] * 1000005
nxt[n] = n
for i in range(n-2,-1,-1):
    if a[i] != a[i+1]:
        nxt[i+1] = i+1
    else:
        nxt[i+1] = nxt[i+2]
for _ in range(m):
    l, r, x = map(int, sys.stdin.readline().split())
    if a[l-1] != x:
        print(l)
    elif nxt[l] < r:
        print(nxt[l]+1)
    else:
        print(-1)
