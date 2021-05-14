n = int(input())
a = list(map(int, input().split()))
if max(a) == min(a):
    # (n - 1)n / 2, triangular number, handshakes, binomial coefficient (n+1, 2), choose 2, etc.
    print(0, ((a.count(max(a)) - 1) * a.count(max(a))) // 2, sep=' ')
else:
    print(max(a) - min(a), a.count(max(a)) * a.count(min(a)), sep=' ')
