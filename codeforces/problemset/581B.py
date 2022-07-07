from collections import defaultdict

n = int(input())
arr = list(map(int, input().split()))

mp = defaultdict(int)
seenb4 = defaultdict(bool)
mx = 0
for i in range(n-1, -1, -1):
    if mx == arr[i]:
        seenb4[i] = True
    mx = max(mx, arr[i])
    mp[i] = mx

for i in range(n):
    if arr[i] == mp[i] and seenb4[i] == False:
        print(0, end=' ')
    else:
        print(mp[i] + 1 - arr[i], end=' ')
