s = []
for i in list(map(int, input().split())):
    if s.count(i) == 0:
        s.append(i)
print(4 - len(s))
