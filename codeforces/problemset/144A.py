n = int(input())
a = list(map(int, input().split()))
mx = [i for i, x in enumerate(a) if x == max(a)]
mn = [i for i, x in enumerate(a) if x == min(a)]

if mx[0] < mn[-1]:
    print(mx[0] + len(a) - mn[-1] - 1)
else:
    print(mx[0] + len(a) - mn[-1] - 2)
