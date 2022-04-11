# The insight here begins with noticing we cannot color the top left square black.
# This leads to noticing if the top left square is white we can color the board
# however we want in at most n*m-1 operations.

# approach, start in the bottom right corner and snake up to the top left corner.
# *<-------
#  _______|
# |_______
#  _______|
# |
# ^-------<

for case in range(int(input())):
    mxR, mxC  = map(int, input().split())
    g = []
    for r in range(mxR):
        g.append([int(x) for x in list(input())])

    if g[0][0] == 1:
        print(-1)
        continue

    ans = []
    for i in range(mxR-1, -1, -1):
        for j in range(mxC-1, -1, -1):
            if g[i][j] == 1:
                if j == 0:
                    ans.append([i+1-1, j+1, i+1, j+1])
                else:
                    ans.append([i+1, j+1-1, i+1, j+1])

    assert(len(ans) < mxR * mxC)
    print(len(ans))
    for l in ans:
        print(*l)

