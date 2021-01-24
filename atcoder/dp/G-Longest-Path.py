import sys
sys.setrecursionlimit(10**9)

n,m = map(int, input().split())
g = [[] for _ in range(n+1)]
for _ in range(m):
    node,neighbor = map(int, input().split())
    g[node].append(neighbor)

# dp[i] is longest path starting from node i which
# is the longest path starting from neighbor j + 1...
dp = [0] * (n+1)

def dfs(i):
    # we've already solved this node
    if dp[i] != 0:
        return dp[i]
    ret = 0
    for j in g[i]:
        ret = max(ret, dfs(j) + 1)
    dp[i] = ret
    return dp[i]
    
ans = 0
for i in range(1, n+1):
    ans = max(ans, dfs(i))
print(ans)
