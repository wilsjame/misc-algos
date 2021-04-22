t = int(input())
for _ in range(t):
    n, k1, k2 = map(int, input().split())
    w, b = map(int, input().split())
    w_cnt = min(k1, k2) + abs(k1 - k2)//2
    k1 = n - k1
    k2 = n - k2
    b_cnt = min(k1, k2) + abs(k1 - k2)//2
    if w_cnt >= w and b_cnt >= b:
        print('YES')
    else:
        print('NO')
