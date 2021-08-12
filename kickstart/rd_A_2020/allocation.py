tt = int(input())
for t in range(1, tt+1):
    n, b = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = 0
    k = 0
    for x in sorted(a):
        k += x
        if k <= b:
            cnt += 1
        else:
            break
    print(f"Case #{t}: {cnt}")
