t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if n % k == 0:
        # n is a multiple of k
        print(1)
    elif n > k:
        print(2)
    else:
        print((k + n - 1) // n)
