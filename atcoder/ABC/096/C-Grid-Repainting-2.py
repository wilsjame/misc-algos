import sys
h, w = map(int, input().split())

b = []
for i in range(h):
    b.append(input())

for i in range(h):
    for j in range(w):
        if b[i][j] == '#':
            yes = False
            if j - 1 >= 0 and b[i][j - 1] == '#':
                yes = True
            if j + 1 < w and b[i][j + 1] == '#':
                yes = True
            if i - 1 >= 0 and b[i - 1][j] == '#':
                yes = True
            if i + 1 < h and b[i + 1][j] == '#':
                yes = True
            if yes == False:
                print("No")
                sys.exit(0)
print("Yes")
