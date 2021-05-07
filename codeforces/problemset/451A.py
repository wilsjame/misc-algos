n, m = map(int, input().split())
turn = 0;
while n > 1 and m > 1:
    n -= 1
    m -= 1
    turn += 1
if turn % 2:
    print('Malvika')
else:
    print('Akshat')
