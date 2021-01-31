a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
d = list(map(int, input().split()))
l, s, r, p = 0, 1, 2, 3
w = False
if a[p]:
    if a.count(1) > 1 or b[l] or c[s] or d[r]:
        w = True
if b[p]:
    if b.count(1) > 1 or c[l] or d[s] or a[r]:
        w = True
if c[p]:
    if c.count(1) > 1 or d[l] or a[s] or b[r]:
        w = True
if d[p]:
    if d.count(1) > 1 or a[l] or b[s] or c[r]:
        w = True
if w == True:
    print("YES")
else:
    print("NO")
