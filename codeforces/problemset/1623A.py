def move(r, c, dr, dc, R, C): # -> r: int , c: int, dr: int, dc: int
    if r + dr > R or r + dr < 1:
        dr = -dr
    r += dr
    if c + dc > C or c + dc < 1:
        dc = -dc
    c += dc
    return r, c, dr, dc

T = int(input())
for _ in range(T):
    R, C, r, c, r_f, c_f = map(int, input().split())

    ans = 0
    dr = 1
    dc = 1
    while r != r_f and c != c_f:
        r, c, dr, dc = move(r, c, dr, dc, R, C)
        ans += 1
    print(ans)
