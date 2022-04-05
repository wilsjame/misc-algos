for case in range(int(input())):
    n = int(input())
    c = list(map(int, input().split(' ')))

    if c.count(1) != 1:
        print('NO')
        continue

    ok = True
    for i in range(0, n-1):
        if c[i+1] - c[i] > 1:
            ok = False
            break

    # nth cyclic shift
    if c[0] - c[n-1] > 1:
        ok = False

    if ok: print("YES")
    else: print("NO")

