for test in range(int(input())):
    n = int(input())
    k = [0] * (n+1)
    q = [0] * (n+1)
    for i in range(1, n+1):
        a = list(map(int, input().split()))
        for j in range(1, a[0]+1):
            if k[a[j]] == 0:
                k[a[j]] = 1
                q[i] = 1
                break
    if k.count(0) == 1:
        print('OPTIMAL')
    else:
        print('IMPROVE')
        k[0] = 1
        q[0] = 1
        print(q.index(0),k.index(0))
