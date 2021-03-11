n, k = map(int, input().split())
a = list(map(int, input().split()))
l, r = 0, 0
ans_idx, ans_len, zeros = 0, 0, 0
while r < n:
    # slide window
    if r < n:
        zeros += a[r] == 0
        r += 1
    if zeros > k:
        zeros -= a[l] == 0
        l += 1

    if r - l > ans_len:
        ans_len = r - l
        ans_idx = l

print(ans_len)
zeros = 0
for i in range(n):
    if i < ans_idx:
        print(a[i], end=' ')
    elif i >= ans_idx and zeros < k:
        zeros += a[i] == 0
        print(1, end=' ')
    else:
        print(a[i], end=' ')
