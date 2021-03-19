T = int(input())
for case_num in range(1, T + 1):
    K = int(input())
    A = list(map(int, input().split()))

    # dp[i][j] is minimum rule breaks for playing note j as the i'th note
    dp = [[10005] * 4 for _ in range(K)]
    for i in range(4):
        dp[0][i] = 0

    for i in range (1, K):
        for last in range(4):
            for curr in range(4):
                if A[i] == A[i - 1]:
                    if curr == last:
                        dp[i][curr] = min(dp[i][curr], dp[i - 1][last])
                    else:
                        dp[i][curr] = min(dp[i][curr], dp[i - 1][last] + 1)
                elif A[i] < A[i - 1]:
                    if curr < last:
                        dp[i][curr] = min(dp[i][curr], dp[i - 1][last])
                    else:
                        dp[i][curr] = min(dp[i][curr], dp[i - 1][last] + 1)
                elif A[i] > A[i - 1]:
                    if curr > last:
                        dp[i][curr] = min(dp[i][curr], dp[i - 1][last])
                    else:
                        dp[i][curr] = min(dp[i][curr], dp[i - 1][last] + 1)

    print("Case #%d: %d" % (case_num, min(dp[K - 1])))
