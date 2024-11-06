import sys
input = sys.stdin.readline
import queue

n, m = map(int, input().split())
graph = [[0] * m for _ in range(n)]
sx, sy = -1, -1

for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == 'X':
            graph[i][j] = -1
        elif s[j] == 'P':
            graph[i][j] = 1
        elif s[j] == 'I':
            graph[i][j] = -1
            sx, sy = i, j

q = queue.Queue()
ans = 0
q.put([sx, sy])

while not q.empty():
    px, py = q.get()
    nlst = [[px + 1, py], [px, py + 1], [px - 1, py], [px, py - 1]]
    for nx, ny in nlst:
        if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] >= 0:
            q.put([nx, ny])
            ans += graph[nx][ny]
            graph[nx][ny] = -1

print(ans if ans > 0 else 'TT')