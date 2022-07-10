from collections import defaultdict

n, k = map(int, input().split())
arr = list(map(int, input().split()))

prs = []
for i in range(n):
    # lvls
    up = ((arr[i] // 10) + 1) * 10
    cur = (up - 1) // 10

    prs.append((up - arr[i], cur))

cnt = 0
for need, cur in sorted(prs):
    if k >= need:
        cnt += + 1
        k -= need
    cnt += cur

cnt = min(cnt + k // 10, n * 10)

print(cnt)
