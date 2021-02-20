n = int(input())
m = list(map(int, input().split()))
s = sum(m)
if s % n == 0:
    res = 0
    for x in m:
        res += abs(x - s//n)
    print(res//2)
else:
    lo,hi = s//n, s//n + 1
    res1,res2 = 0,0
    for x in m:
        if x < lo:
            res1 += lo - x
        elif x > hi:
            res2 += x - hi
    print(max(res1, res2))
