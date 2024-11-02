import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

n, m, r = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

order = 1
visit = [0 for _ in range(n + 1)]

def dfs(p):
    global order
    visit[p] = order
    order += 1

    graph[p].sort(reverse=True)
    for np in graph[p]:
        if visit[np] == 0:
            dfs(np)

dfs(r)

for i in range(1, n + 1):
    print(visit[i])