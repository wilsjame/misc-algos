n,m,z = map(int, input().split())

ans = 0
for t in range (1,z+1):
    if t % n == 0 and t %m == 0:
        ans += 1
print(ans)
