t = int(input())
for tc in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(1, n-1):
        ans += (a[i-1] < a[i]) and (a[i] > a[i+1])
    print(f"Case #{tc+1}: {ans}")