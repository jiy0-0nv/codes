import sys
input = sys.stdin.readline

from collections import deque

n, m = map(int, input().split())
maze = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    s = input().strip()
    for j in range(m):
        if s[j] == '1':
            maze[i][j] = 1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(sx, sy):

    q = deque([(sx, sy)])

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx and nx < n and 0 <= ny and ny < m and maze[nx][ny] == 1:
                maze[nx][ny] = maze[x][y] + 1
                q.append((nx, ny))

    return maze[n-1][m-1]

print(bfs(0, 0))