for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = {}
    for x in a:
        if x in d:
            d[x] += 1
        else:
            d[x] = 1
    m = sum(a) / len(a)
    goal = sum(a) - (m * n - 2 * m)
    s = set()
    cnt = 0
    for x in a:
        if x in s:
            continue
        if x in d:
            ka = d[x]
        else:
            ka = 0
        if goal - x in d:
            kb = d[goal - x]
        else:
            kb = 0
        if x == goal - x:
            cnt += (ka * (ka - 1)) / 2
        else:
            cnt += ka * kb
        s.add(x)
        s.add(goal - x)
    print(int(cnt))
