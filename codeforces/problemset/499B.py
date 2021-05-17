n, m = map(int, input().split())
d = {}
for _ in range(m):
    a, b = input().split()
    if len(a) <= len(b):
        a, b = b, a
    d[a] = b
for x in list(input().split()):
    if x in d:
        print(d[x], end=' ')
    else:
        print(x, end=' ')
