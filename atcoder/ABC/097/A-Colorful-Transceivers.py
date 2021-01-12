a,b,c,d = map(int, list(input().split()))
ab = abs(a-b)
bc = abs(b-c)
ac = abs(a-c)

if ac <= d or (ab <= d and bc <= d):
    print("Yes")
else:
    print("No")
