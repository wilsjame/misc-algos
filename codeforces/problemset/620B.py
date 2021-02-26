a,b = map(int, input().split())
cost = [6,2,5,5,4,5,6,3,7,6]
ans = 0
for i in range(a, b+1):
    while i:
        digit = i % 10
        ans += cost[digit]
        i = i // 10
print(ans)
