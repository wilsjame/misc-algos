t = int(input())
for _ in range(t):
    n = input()
    mx = 0
    for x in n:
        mx = max(mx, int(x))
    print(mx)
