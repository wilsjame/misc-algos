N = int(input())
x = []
for i in range(N):
    a,b,c = map(int, input().split())
    x.append([a,b,c])

dp = [[0 for i in range(3)] for j in range(N+1)]

for i in range (1, N+1):
    dp[i][0] = max(dp[i-1][1] + x[i-1][0], dp[i-1][2] + x[i-1][0])
    dp[i][1] = max(dp[i-1][0] + x[i-1][1], dp[i-1][2] + x[i-1][1])
    dp[i][2] = max(dp[i-1][0] + x[i-1][2], dp[i-1][1] + x[i-1][2])
print(max(dp[N]))
