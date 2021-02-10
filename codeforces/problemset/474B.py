n = input()
a = list(map(int, input().split()))
m = input()
q = list(map(int, input().split()))

A = []
p = 1
for x in a:
    for _ in range(x):
        A.append(p)
    p += 1

for i in q:
    print(A[i-1])
