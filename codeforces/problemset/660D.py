n = int(input())
a = []
for _ in range(n):
    xy = list(map(int, input().split()))
    a.append(xy)
midpoint = {}
for i in range(n):
    for j in range(i + 1, n):
        x1, y1 = a[i][0], a[i][1]
        x2, y2 = a[j][0], a[j][1]
        dx = x2 + x1
        dy = y2 + y1
        midpoint[(dx / 2, dy / 2)] = midpoint.get((dx / 2, dy / 2), 0) + 1
ans = 0
for k, v in midpoint.items():
    # choose 2
    ans += (v * (v - 1)) // 2 
print(ans)

#import matplotlib.pyplot as plt
#import numpy as np
#x, y = zip(*a)
#plt.scatter(x, y)
#plt.grid()
#plt.show()
