n,x = map(int, input().split())

ans = 0
for i in range(1,n+1):
    mx = i * n
    if x % i == 0 and x <= mx:
        ans += 1
print(ans)
