t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = {}
    for x in a:
        if x in cnt:
            cnt[x] += 1
        else:
            cnt[x] = 1
    size = n
    same = cnt[max(cnt, key=cnt.get)]
    unique = len(cnt)
    if same == unique:
        print(same - 1)
    elif same < unique:
        print(same) 
    elif same > unique:
        print(unique)
