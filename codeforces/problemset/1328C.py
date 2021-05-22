t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int, input()))
    a = [] # minimize
    b = []
    seen = False
    for i in x:
        if i == 0:
            a.append(0)
            b.append(0)
        elif i == 1:
            if seen:
                a.append(1)
                b.append(0)
            elif not seen:
                a.append(0)
                b.append(1)
            seen = True
        elif i == 2:
            if seen:
                a.append(2)
                b.append(0)
            elif not seen:
                a.append(1)
                b.append(1)
    print(*a, sep='')
    print(*b, sep='')
