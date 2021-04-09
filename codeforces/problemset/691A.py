n = int(input())
a = list(map(int, input().split()))

cnt = a.count(1)
if n == 1:
    if cnt == 1:
        print('YES')
    else:
        print('NO')
elif n > 1:
    if cnt == n - 1:
        print('YES')
    else:
        print('NO')
