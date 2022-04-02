# Monotonic function which returns
# true if size x is possible for each heap.
def ok(x, h_og, h_cur):
    # iterate right to left to the 2nd heap
    for i in range(len(h_og)-1, 1, -1):
        if h_cur[i] < x:
            # impossible to have x
            return False
        # most we can take from h_i and still have x
        d = min(h_og[i], h_cur[i] - x) // 3
        h_cur[i-1] += d
        h_cur[i-2] += 2*d

    return h_cur[0] >= x and h_cur[1] >= x

for testcase in range(int(input())):
    N = int(input())
    h_og = list(map(int, input().split()))

    # find the largest value of x where ok(x) holds true
    l = 0
    r = max(h_og)
    while l <= r:
        m = (l + r) // 2
        h_cur = [x for x in h_og]
        if ok(m, h_og, h_cur):
            # valid at m, shift right to get the largest value
            l = m + 1
        else:
            r = m - 1
    # r holds the ans
    print(r)

