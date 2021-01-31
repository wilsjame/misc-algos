n = int(input())
a = list(map(int, input().split()))
b = []

for i in range(0, n - 1):
    b.append(a[i] + a[i + 1])
b.append(a[n - 1])

print(*b)


