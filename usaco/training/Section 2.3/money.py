"""
ID: jgwilso1
LANG: PYTHON3
TASK: money
"""
fin = open ('money.in', 'r')
fout = open ('money.out', 'w')
V,N  = map(int, fin.readline().split())
coin = list()
while len(coin) < V:
    line = list(map(int, fin.readline().split()))
    for x in line:
        coin.append(x)
# dp ways to make change j using the first i coins
nway = [[0 for j in range(N + 1)] for i in range(V)]
for i in range(V):
    nway[i][0] = 1
    for j in range(N + 1):
        if i > 0:
            nway[i][j] = nway[i - 1][j]
        if j - coin[i] >= 0:
            nway[i][j] += nway[i][j - coin[i]]
ans = nway[V - 1][N]
fout.write (str(ans) + '\n')
fout.close()
