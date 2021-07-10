t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    # greedy
    ans = 0
    for i in range(1, n):
        m = 0
        if p[i] / p[0] > k / 100:
            # ceiling and // floor 
            m = ((100 * p[i] - k * p[0]) + k - 1) // k
        p[0] += p[i] + m
        ans += m
    print(int(ans))
