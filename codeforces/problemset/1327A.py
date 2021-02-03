for _ in range(int(input())):
    n,k = map(int, input().split())
    n -= (k-1)**2
    if n >= 2*(k-1)+1 and n % 2 != 0:
        print('YES')
    else:
        print('NO')
