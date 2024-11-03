import queue
import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())

graph = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [0 for _ in range(n + 1)]
q = queue.Queue()

# bfs
order = 1
visited[r] = order
q.put(r)

while q.qsize() > 0:
    p = q.get()
    graph[p].sort()
    for np in graph[p]:
        if visited[np] == 0:
            order += 1
            visited[np] = order
            q.put(np)

for i in range(1, n + 1):
    print(visited[i])