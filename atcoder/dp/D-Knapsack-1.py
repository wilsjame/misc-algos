N,W = map(int, input().split())
w = []
v = []
for _ in range(N):
    weight,value = map(int, input().split())
    w.append(weight)
    v.append(value)

# rows = items, cols = weights
# dp[i][j] = maximum value for weight j using first i items 
dp = [[0 for col in range(W+1)] for row in range(N+1)]

for i in range(1, N+1):
    for j in range(0, W+1):
        w_i = w[i-1]
        v_i = v[i-1]
        if j - w_i >= 0:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w_i] + v_i)
        else:
            dp[i][j] = dp[i-1][j]
print(dp[N][W])
