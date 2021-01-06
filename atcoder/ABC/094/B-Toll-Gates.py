N, M, X = map(int, input().split())
A = map(int, input().split())

L = 0
R = 0

for ai in A:
    if ai < X:
        L += 1
    elif ai > X:
        R += 1

print(min(L, R))
