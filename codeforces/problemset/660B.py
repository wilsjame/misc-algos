n, m = map(int, input().split()) 
# a,b,c,d = left window, left non-window, right non-window, right window
a, b, c, d = [], [], [], []
for i in range(n):
    if 2 * i + 1 <= m:
        a.append(2 * i + 1)
for i in range(n, 2 * n):
    if 2 * i + 1 <= m:
        b.append(2 * i + 1)
for i in range(1, n + 1):
    if 2 * i <= m:
        d.append(2 * i)
for i in range(n + 1, 2 * n + 1):
    if 2 * i <= m:
        c.append(2 * i)
ans = []
for i in range(m):
    if len(b):
        ans.append(b[0])
        b.pop(0)
    if len(a):
        ans.append(a[0])
        a.pop(0)
    if len(c):
        ans.append(c[0])
        c.pop(0)
    if len(d):
        ans.append(d[0])
        d.pop(0)
    if len(ans) == m:
        break
print(*ans)
