import sys # TLE without
n, m = map(int, input().split())

pos = [None] * (n + 1)
for i, a in enumerate(map(int, input().split())):
    pos[a] = i

z = [300005] * (n + 1)
for pr in sys.stdin.read().splitlines():
    x, y = map(int, pr.split())
    if pos[x] > pos[y]:
        x, y = y, x
    z[pos[x]] = min(z[pos[x]], pos[y])

lf, rg, ans = n - 1, n - 1, 0
while lf >= 0:
    rg = min(rg, z[lf] - 1)
    ans += rg - lf + 1
    lf -= 1

print(ans)
