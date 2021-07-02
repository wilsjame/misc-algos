t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    ans = 0
    while r != 0 or l != 0:
        ans += r - l
        r //= 10
        l //= 10
    print(ans)
