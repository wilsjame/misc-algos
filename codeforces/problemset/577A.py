n,x = map(int, input().split())

ans = sum((x % i == 0 and x <= i * n) for i in range(1,n+1))
print(ans)
