# Two approaches here:
# One, we could scan each black coloring and check if it is a rectangle.
# Two (hackish), scan each 2x2 region and if exactly 3 squares are colored
# black we know a coloring is not a rectangle.  

# approach two:
for case in range(int(input())):
    #print("case ", case+1)
    mxR, mxC  = map(int, input().split())
    g = []
    for r in range(mxR):
        g.append([int(x) for x in list(input())])
    
    # region is smaller than 2x2
    if mxR * mxC < 4 and g.count(1) < 0:
        print('yes')
        continue

    ok = True
    for i in range(mxR-1):
        for j in range(mxC-1):
            cnt = 0
            cnt += g[i][j] == 1
            cnt += g[i][j+1] == 1
            cnt += g[i+1][j] == 1
            cnt += g[i+1][j+1] == 1
            if cnt == 3:
                ok = False

    if ok:
        print('yes')
    else:
        print('no')

