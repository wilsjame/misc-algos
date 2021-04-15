n, m = map(int, input().split())
a = list(map(int, input().split())) # increasing order
b = list(map(int, input().split())) # increasing order

# find the two nearest towers for each city: two pointers O(linear)
# they will be the tower before and after the city (one may be on the city)
# handle furthest left and right towers with 0, and m - 1 indices
l, r = 0, 0
ans = [None] * n
for i in range(n):
    while r < m and b[r] < a[i]:
        r += 1
    # now b[r] is greater than a[i] or r == m
    r = min(r, m - 1)
    l = max(0, r - 1)
    rd = abs(a[i] - b[r])
    ld = abs(a[i] - b[l])
    ans[i] = min(rd, ld)
print(max(ans))
