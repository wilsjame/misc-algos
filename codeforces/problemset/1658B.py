for case in range(int(input())):
    N = int(input())
    if N % 2 > 0:
        print(0)
    else:
        n = N // 2
        ans = 1
        while n > 0:
            ans *= n
            ans %= 998244353
            n -= 1
        ans *= ans
        ans %= 998244353
        print(ans)

