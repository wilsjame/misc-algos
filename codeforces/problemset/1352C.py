t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    shifts = k // (n - 1)
    ans = k + shifts
    if k % (n - 1) == 0:
        ans -= 1
    print(ans)
