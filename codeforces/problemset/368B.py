n, m = map(int, input().split())
a = list(map(int, input().split()))
a.reverse()
# suffix like sums
sums = [None] * n
cnt = {}
for i in range(n):
    cur = a[i]
    if cur not in cnt:
        cnt[cur] = 1
    sums[i] = len(cnt)
sums.reverse()
for _ in range(m):
    l = int(input())
    print(sums[l - 1])
