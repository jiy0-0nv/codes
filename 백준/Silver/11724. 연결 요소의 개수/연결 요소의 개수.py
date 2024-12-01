from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

ans = 0
visit = [0] * n

def bfs(s, g, v):
    q = deque([s])
    v[s] = 1

    while q:
        t = q.popleft()
        for k in g[t]:
            if not v[k]:
                v[k] = 1
                q.append(k)

for i in range(n):
    if not visit[i]:
        bfs(i, graph, visit)
        ans += 1

print(ans)