n, a, b = map(int, input().split())
if n - (a + b) > 1:
    a += n - (a + b) - 1
print(n - a)
