t = int(input())
for _ in range(t):
    a, b, x, y, n = map(int, input().split()) 
    dx = a - x
    dy = b - y
    # greedy a, b
    p1 = (a - min(dx, n)) * (b - min(dy, n - min(dx, n)))
    p2 = (b - min(dy, n)) * (a - min(dx, n - min(dy, n)))
    ans = min(p1, p2)
    print(ans)
