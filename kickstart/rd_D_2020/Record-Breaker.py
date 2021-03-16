T = int(input())
for case_num in range(1, T + 1):
    N = int(input())
    V = list(map(int, input().split()))
    V.append(-1)
    s = 0
    mx = V[0]
    for i in range(N):
        cur = V[i]
        nxt = V[i+1]
        if i == 0 and cur > nxt or cur > mx and cur > nxt:
            s += 1
            mx = cur
    print("Case #%d: %d" % (case_num, s))
