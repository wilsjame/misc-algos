n, m = map(int, input().split())
mx = (n - m) + 1
mn1 = (n // m) + 1
mn2 = n // m

ans_mx = ((mx - 1) * mx) // 2
ans_mn = (n % m) * ((mn1 - 1) * mn1) // 2
ans_mn += (m - (n % m)) * ((mn2- 1) * mn2) // 2
print(ans_mn, ans_mx, sep=' ')
