s = input()
t = input()

dp = [[0 for col in range(len(s)+1)] for row in range(len(t)+1)]

# fill table
for i in range(1, len(t)+1):
    for j in range(1, len(s)+1):
        if t[i-1] == s[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

# trace back build lcs
ans = ""
i = len(t)
j = len(s)
while i and j:
    if t[i-1] == s[j-1]:
        ans = t[i-1] + ans
        i -= 1
        j -= 1
    else:
        if dp[i][j] == dp[i-1][j]:
            i -= 1
        else:
            j -= 1

print(ans)
