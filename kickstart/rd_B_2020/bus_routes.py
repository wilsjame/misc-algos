t = int(input())
for tc in range(t):
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    latest = d
    for xi in reversed(a):
        latest = (latest//xi)*xi
    print(f"Case #{tc+1}: {latest}")