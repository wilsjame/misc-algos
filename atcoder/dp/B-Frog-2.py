N,K = map(int, input().split())
h = list(map(int, input().split()))
INF = 10**9

dp = [INF]*(N)
dp[0] = 0

for i in range (N):
    for j in range(1, K+1):
        if i+j < N:
            dp[i+j] = min(abs(h[i] - h[i+j]) + dp[i], dp[i+j])
print(dp[N-1])
