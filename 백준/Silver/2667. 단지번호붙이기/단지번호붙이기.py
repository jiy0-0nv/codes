import sys
input = sys.stdin.readline

from collections import deque

n = int(input())
map = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    s = input().strip()
    for j in range(n):
        if s[j] == '1':
            map[i][j] = 1

ans = []

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(sx, sy):

    q = deque([(sx, sy)])
    map[sx][sy] = 0
    cnt = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx and nx < n and 0 <= ny and ny < n and map[nx][ny] == 1:
                map[nx][ny] = 0
                cnt += 1
                q.append((nx, ny))

    return cnt

for i in range(n):
    for j in range(n):
        if map[i][j] == 1:
            ans.append(bfs(i, j))

print(len(ans))
ans.sort()
for i in ans:
    print(i)