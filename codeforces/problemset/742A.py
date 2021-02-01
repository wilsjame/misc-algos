n = int(input())
if n == 0:
    ans = 1
elif n == 1:
    ans = 8;
else:
    r = n % 4
    if r == 1:
        ans = 8
    elif r == 2:
        ans = 4
    elif r == 3:
        ans = 2
    elif r == 0:
        ans = 6
print(ans)
