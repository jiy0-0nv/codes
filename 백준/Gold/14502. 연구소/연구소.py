from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
lab = [list(map(int, input().split())) for _ in range(n)]

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

vl = []
bl = []
for i in range(n):
    for j in range(m):
        if lab[i][j] == 2:
            vl.append([i, j])
        elif lab[i][j] == 0:
            bl.append([i, j])
bn = len(bl)

def bfs():
    b = len(bl) - 3
    q = deque(vl)
    g = [l[:] for l in lab]
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and g[nx][ny] == 0:
                g[nx][ny] = 1
                q.append([nx, ny])
                b -= 1
    return b

ans = 0

for i in range(bn):
    lab[bl[i][0]][bl[i][1]] = 1
    for j in range(i + 1, bn):
        lab[bl[j][0]][bl[j][1]] = 1
        for k in range(j + 1, bn):
            lab[bl[k][0]][bl[k][1]] = 1
            ans = max(ans, bfs())
            lab[bl[k][0]][bl[k][1]] = 0
        lab[bl[j][0]][bl[j][1]] = 0
    lab[bl[i][0]][bl[i][1]] = 0

print(ans)