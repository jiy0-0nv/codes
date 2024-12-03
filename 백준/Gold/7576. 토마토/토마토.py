# BFS
from collections import deque
import sys
input = sys.stdin.readline

m, n = map(int, input().split())
box = [list(map(int, input().split())) for _ in range(n)]

q = deque([])

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
ans = 0

for i in range(n):
    for j in range(m):
        if box[i][j] == 1:
            q.append([i, j])

def bfs():
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and box[nx][ny] == 0:
                box[nx][ny] = box[x][y] + 1
                q.append([nx, ny])

bfs()

for r in box:
    for t in r:
        if t == 0:
            print(-1)
            exit(0)
    ans = max(ans, max(r))

print(ans - 1)