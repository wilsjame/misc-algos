a,b = map(int, input().split())
for i in range(1,1000):
    x = (i*(i+1))/2
    y = (i+1)*(i+2)/2
    if y - x == b - a:
        print(int(x - a))
        exit(0)
