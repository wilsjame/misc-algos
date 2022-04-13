for case in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    bag = set([int(x) for x in range(1, n+1)])
    bag2 = set()
    for x in arr:
        while x > 0:
            if x in bag and x not in bag2:
                bag2.add(x)
                break
            x = x // 2

    if len(bag) == len(bag2):
        print('yes')
    else:
        print('no')

