n, m = map(int, input().split())
moves = n // 2 + n % 2
while moves % m != 0:
    moves += 1
if moves <= n:
    print(moves)
else:
    print(-1)
