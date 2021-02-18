n,m = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for i in range(m+1):
    for j in range(i+1, m+1):
        ans += a.count(i) * a.count(j)
print(ans)
