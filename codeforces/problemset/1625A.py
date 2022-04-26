# each bit is independent so we can inspect 
# each one and greedily choose values
for case in range(int(input())):
    n, l = map(int, input().split())
    arr = [format(x, '030b') for x in list(map(int, input().split()))]
    ans = [None for _ in range(30)]
    for i in range(0, 30):
        cnt_1 = 0
        cnt_0 = 0
        for x in arr:
            cnt_1 += x[i] == '1'
            cnt_0 += x[i] == '0'
        if cnt_1 > cnt_0:
            ans[i] = '1'
        else:
            ans[i] = '0' 
    print(int(''.join(ans), 2))

