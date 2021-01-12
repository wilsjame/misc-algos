s = input()
k = int(input())
x = set()

for i in range(1,6):
    for j in range(len(s)-i+1):
        x.add(s[j:j+i])
y = sorted(list(x))
print(y[k-1])
