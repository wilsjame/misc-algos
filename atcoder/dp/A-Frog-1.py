N = int(input())
h = list(map(int, input().split()))
INF = 10**9

dp = [INF]*(N)
dp[0] = 0

for i in range (N):
    if i+1 < N:
        dp[i+1] = min(abs(h[i] - h[i+1]) + dp[i], dp[i+1])
    if i+2 < N:
        dp[i+2] = min(abs(h[i] - h[i+2]) + dp[i], dp[i+2])
print(dp[N-1])
