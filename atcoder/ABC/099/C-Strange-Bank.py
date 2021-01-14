n = int(input())
INF = 1e9
maxn = 1e5

# seed valid single withdrawal values 
w = [1] 
z = 1
while 9**z <= maxn:
    w.append(9**z)
    z += 1
z = 1
while 6**z <= maxn:
    w.append(6**z)
    z += 1

# dp[i] stores the optimal solution for value i
dp = [INF]*(n+1)
dp[0] = 0
for i in range(1,n + 1):
    for withdraw in w:
        if i - withdraw >= 0:
            dp[i] = min(dp[i-withdraw] + 1, dp[i]) 
print(dp[n])
