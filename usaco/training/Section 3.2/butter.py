"""
ID: jgwilso1
LANG: PYTHON3
TASK: butter
"""
import heapq

fin = open ('butter.in', 'r')
fout = open ('butter.out', 'w')
N, P, C = map(int, fin.readline().split())

# store in table number of cows in each pasture
ncow = [0 for _ in range(P + 1)]
for _ in range(N):
    p = int(fin.readline())
    ncow[p] += 1

# create graph using adjacency list
adj = [[] for _ in range(P + 1)]
for _ in range(C):
    a, b, dist = map(int, fin.readline().split()) 
    adj[a].append((b, dist))
    adj[b].append((a, dist))

# shortest path every pasture w/ dijkstra's
res = 1e9
for source in range(1, P + 1):
    pq = []
    shortest_path = [1e9 for _ in range(P + 1)]
    processed = [False for _ in range(P + 1)]
    heapq.heappush(pq, (0, source))
    shortest_path[source] = 0
    while len(pq) > 0:
        top = heapq.heappop(pq)
        u = top[1]
        if processed[u] is True:
            continue
        processed[u] = True
        for neighbor in adj[u]:
            v = neighbor[0]
            d = neighbor[1]
            if shortest_path[u] + d < shortest_path[v]:
                shortest_path[v] = shortest_path[u] + d
                heapq.heappush(pq, (shortest_path[v], v))
    cnt = 0
    for i in range(1, P + 1):
        cnt += shortest_path[i] * ncow[i]
    res = min(res, cnt)

fout.write (str(res) + '\n')
fin.close()
fout.close()
