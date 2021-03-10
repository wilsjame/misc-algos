n = int(input())
a = map(int, input().split())
a = sorted(a)
b = []
for i in range(n//2):
        b.append(a[i])
        b.append(a[n-1-i])
if len(a) % 2:
    b.append(a[n//2])
print(*b)

