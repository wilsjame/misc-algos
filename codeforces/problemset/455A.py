n = int(input())
cnt = [0] * (10**5+5)
a = list(map(int, input().split()))
for x in a:
    cnt[x] += 1
# dp[i] = max val if i was the last number picked
dp = [0] * (10**5+5) 
dp[a[0]] = cnt[a[0]]*a[0]
for i in range(1, n+1):
        dp[i] = max(cnt[i]*i + dp[i-2], dp[i-1])
print(max(dp))
