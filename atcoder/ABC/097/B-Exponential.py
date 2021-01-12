x = int(input())
ans = 1
diff = 1005
b = 2
while b * b <= x:
    bp = b
    while bp * b <= x:
        bp = bp * b
    if x - bp < diff:
        diff = x - bp
        ans = bp
    b += 1
print(ans)
