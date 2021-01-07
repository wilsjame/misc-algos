A, B, C, X, Y = map(int, input().split())
minxy = min(X, Y)
minab = min(A + B, 2 * C)
mina = min(A, 2 * C)
minb = min(B, 2 * C)
X = X - minxy
Y = Y - minxy

ans = minxy * minab + X * mina + Y * minb
print(ans)
