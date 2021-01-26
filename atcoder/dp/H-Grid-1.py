h,w = map(int, input().split())
grid = [list(input()) for i in range(h)]
MOD = 10**9 + 7

dp = [[0 for j in range(w)] for i in range(h)]
dp[0][0] = 1

for i in range(h):
    for j in range(w):
        if i == 0 and j == 0 or grid[i][j] == '#':
            continue
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
        dp[i][j] %= MOD

print(dp[h-1][w-1])

