n = int(input())
p = list((input().split()))

# dp[i][j] probability we have j heads from throwing i coins
dp = [[0 for j in range (n+1)] for i in range (n+1)]
dp[0][0] = 1

for i in range(1, n+1):
    p_head = float(p[i-1])
    p_tail = 1 - p_head
    for j in range(0, i+1):
        # dp[i][j] = prob heads (build up we toss heads) +
        #            prob not heads (stay in same column we toss tails)
        if j == 0:
            dp[i][j] = dp[i-1][j] * p_tail
        else:
            dp[i][j] = dp[i-1][j-1] * p_head + dp[i-1][j] * p_tail

# ceil(n/2)
z = (n + 2 - 1) // 2 
ans = 0
for j in range(z, n+1):
    ans += dp[n][j]
print(ans)
