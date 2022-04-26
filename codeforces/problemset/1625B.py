# Greedy one pass, at index i always line up with
# the nearest same element to its right.
# Store positions of nearest same element w/ map.
for case in range(int(input())):
    n = int(input())
    arr = list(input().split())

    mp = {}
    best = 0
    for i in range(n):
        if arr[i] in mp:
            best = max(best, mp[arr[i]] + n - i)
        mp[arr[i]] = i

    if best == 0:
        print(-1)
    else:
        print(best)

