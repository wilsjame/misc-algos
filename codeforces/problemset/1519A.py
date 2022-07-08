N = int(input())
for case in range(N):
    a, b, d = map(int, input().split())

    if abs(a - b) <= d:
        print('yes')
    else:
        # greedy, spread minimum color
        minbeans = min(a, b)

        # max allowable d
        dtotal = minbeans * d

        # need to pair beans
        mxbeans = max(a, b)
        mxbeans -= minbeans

        # beans to play with
        if mxbeans <= dtotal:
            print('yes')
        else:
            print('no')
