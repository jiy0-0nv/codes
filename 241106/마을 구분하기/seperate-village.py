import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
graph = [0 for _ in range(n)]


for i in range(n):
    graph[i] = list(map(int, input().split()))

def dfs(sx, sy, sp):
    p = sp
    graph[sx][sy] = 0
    lst = [[sx + 1, sy], [sx - 1, sy], [sx, sy + 1], [sx, sy - 1]]
    for nx, ny in lst:
        if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == 1:
            p = dfs(nx, ny, p + 1)
    return p

ans = 0
plst = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            plst.append(dfs(i, j, 1))
            ans += 1

print(ans)
plst.sort()
for p in plst:
    print(p)