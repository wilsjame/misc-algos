import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    u = list(map(int, input().split()))
    s = list(map(int, input().split()))
    d = {}
    # input
    for i in range(n):
        if u[i] in d:
            d[u[i]].append(s[i])
        else:
            d[u[i]] = [s[i]]
    # prefix sums
    prefix = {}
    for i in d:
        d[i].sort(reverse=True)
        prefix[i] = [0]
        for j in range(len(d[i])):
            prefix[i].append(prefix[i][j] + d[i][j])
    # solve
    ans = [0] * n
    for k in range(1, n + 1):
        for i in d:
            mx = (len(d[i]) // k ) * k
            ans[k - 1] += prefix[i][mx]
    print(*ans)
