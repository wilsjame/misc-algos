#TODO O(log(n))
n,m = map(int, input().split())
mx = 20005

q = []
visited = [0]*mx
distance = [0]*mx

q.append(n)
visited[n] = 1
distance[n] = 0
#BFS
while q:
    x = q[0]
    q.pop(0)
    if x > 0 and not visited[x-1]:
        visited[x-1] = 1
        distance[x-1] = distance[x]+1
        q.append(x-1)
    if x <= m and not visited[2*x]:
        visited[2*x] = 1
        distance[2*x] = distance[x]+1
        q.append(2*x)
print(distance[m])
