import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[n for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(n + 1):
    graph[i][i] = 0

for _ in range(m):
    x, y = map(int, input().split())
    graph[x][y] = 1
    graph[y][x] = 1

for c in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            if graph[a][b] > graph[a][c] + graph[c][b]:
                graph[a][b] = graph[a][c] + graph[c][b]
                graph[b][a] = graph[c][a] + graph[b][c]

ansn = n * n
ans = 0
for i in range(1, n + 1):
    if ansn > sum(graph[i]):
        ansn = sum(graph[i])
        ans = i

print(ans)