import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m, r = map(int, input().split())

graph = [[] for _ in range(n + 1)]
visit = [0 for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

order = 1

def dsf(p):
    global order
    visit[p] = order
    order += 1
    graph[p].sort()
    for j in graph[p]:
        if visit[j] == 0:
            dsf(j)

dsf(r)

for i in range(1, n + 1):
    print(visit[i])