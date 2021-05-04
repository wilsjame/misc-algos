t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a == b:
        print(0)
    elif a < b:
        print(b - a)
    elif a > b:
        ceil =  (a + b - 1) // b
        print(ceil * b - a)
