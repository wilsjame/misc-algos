n, k = map(int, input().split())
s = input()

ans = [] # too slow if string
for x in s:
    da = abs(ord(x) - ord('a'))
    dz = abs(ord(x) - ord('z'))
    if da > dz and da <= k:
        ans.append('a')
        k -= da
    elif dz > da and dz <= k:
        ans.append('z')
        k -= dz
    elif k > 0:
        for y in "abcdefghijklmnopqrstuvwxyz":
            if abs(ord(y) - ord(x)) == k:
                ans.append(y)
                k = 0
                break
    else:
        ans.append(x)
if k != 0:
    print(-1)
else:
    print(''.join(ans))
