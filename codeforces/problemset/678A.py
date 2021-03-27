n, k = map(int, input().split())
ceil = (n + k - 1) // k
if ceil * k > n:
    print(ceil * k)
else:
    print(ceil * k + k)
