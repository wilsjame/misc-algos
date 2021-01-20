N,W = map(int, input().split())
w = []
v = []
V = int(1e5) # problem constraints
INF = int(1e9+5)
for _ in range(N):
    weight,value = map(int, input().split())
    w.append(weight)
    v.append(value)

# rows = items, cols = values
# dp[i][j] = minimum weight for value j using first i items 
dp = [[INF for col in range(V+1)] for row in range(N+1)]
dp[0][0] = 0

for i in range(1, N+1):
    for j in range(0, V+1):
        w_i = w[i-1]
        v_i = v[i-1]
        if j - v_i >= 0:
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-v_i] + w_i)
        else:
            dp[i][j] = dp[i-1][j]
maxval = 0
for j in range(1, V+1):
    w_j = dp[N][j]
    if w_j <= W:
        maxval = max(maxval, j)
print(maxval)
