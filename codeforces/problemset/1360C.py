t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    odd = 0
    even = 0
    one = 0
    a.sort()
    for x in a:
        if x % 2:
            odd += 1
        else:
            even += 1
    for i in range(n - 1):
        cur = a[i]
        nxt = a[i + 1]
        if abs(cur - nxt) == 1:
            one += 1
    if even % 2 == 0 and odd % 2 == 0:
        print('YES')
    elif (even % 2 and odd % 2) and one > 0: 
        print('YES')
    else:
        print('NO')
