import sys
input = sys.stdin.readline

sys.setrecursionlimit(10000)

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def dfs(g, x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if (0 <= nx < m) and (0 <= ny < n):
            if g[ny][nx] == 1:
                g[ny][nx] = 0
                dfs(g, nx, ny)

t = int(input())

for _ in range(t):
    m, n, k = map(int, input().split())
    graph = [[0 for _ in range(m)] for _ in range(n)]
    ans = 0

    for _ in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1

    for x in range(m):
        for y in range(n):
            if graph[y][x] == 1:
                dfs(graph, x, y)
                ans += 1

    print(ans)