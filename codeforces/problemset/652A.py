h1, h2 = map(int, input().split())
a, b = map(int, input().split())
# day 0
day = 0
h1 += 8 * a
if h1 >= h2:
    print(day)
    exit()
h1 -= 12 * b;
# day 1 and beyond
if h1 + 12 * a < h2 and a <= b:
    print(-1)
else:
    while True:
        h1 += 12 * a
        day += 1
        if h1 >= h2:
            print(day)
            exit()
        h1 -= 12 * b
