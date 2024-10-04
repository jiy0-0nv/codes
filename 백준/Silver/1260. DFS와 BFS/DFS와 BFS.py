import sys
input = sys.stdin.readline

n, m, v = map(int,input().split())

graph = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = graph[b][a] = 1

vst = [0 for _ in range(n + 1)]

def dfs(v):
    vst[v] = 1
    print(v, end=' ')
    for i in range(1, n + 1):
        if graph[v][i] == 1 and vst[i] == 0:
            dfs(i)

def bfs(v):
    queue = [v]
    vst[v] = 1
    while queue:
        v = queue.pop(0)
        print(v, end = ' ')
        for i in range(1, n + 1):
            if(vst[i] == 0 and graph[v][i] == 1):
                queue.append(i)
                vst[i] = 1

dfs(v)
print()
vst = [0 for _ in range(n + 1)]
bfs(v)