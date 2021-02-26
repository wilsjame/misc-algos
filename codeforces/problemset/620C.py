n = int(input())
a = list(map(int, input().split()))
# greedy
used = {}
x,y = [],[]
for i in range(n):
    if not used:
        used[a[i]] = 1
        x.append(i)
    elif a[i] in used and used[a[i]] == 1:
        y.append(i)
        used = {}
    else:
        used[a[i]] = used.get(a[i],0) + 1

if not y:
    print(-1)
else:
    if len(x) > len(y):
        del x[-1]
    y[-1] = n-1
    print(len(x))
    for i in range(len(x)):
        print(x[i]+1,y[i]+1)
