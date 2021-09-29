t = int(input())
for _ in range(t):
    s = input()
    na = s.count('A')
    nb = s.count('B')
    nc = s.count('C')
    if na <= nb and nb - na == nc:
        print('YES')
    else:
        print('NO')
