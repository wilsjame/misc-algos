t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    o = 0
    e = 0
    for i in a:
        if i % 2:
            o += 1
        else:
            e += 1
    ok = False
    for i in range(1, min(o, x) + 1, 2):
        if i % 2 and e >= x - i:
            ok = True
            break
    if ok:
        print('Yes')
    else:
        print('No')
