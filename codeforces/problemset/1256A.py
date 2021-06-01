q = int(input())
for _ in range(q):
    a, b, n, S = map(int, input().split())
    need = S // n
    have = n * min(a, need)
    if b >= S - have:
        print('YES')
    else:
        print('NO')
    
