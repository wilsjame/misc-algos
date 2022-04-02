for t in range(int(input())):
    N = int(input())
    mp = {}
    rset = set()
    for _ in range(N):
        r = tuple(map(int, input().split()))
        rset.add(r)

    for l, r in rset:
        for p in range(l, r+1):
            if (p == l or (l, p-1) in rset) and (p == r or (p+1, r) in rset):
                print(l, r, p)
                break
