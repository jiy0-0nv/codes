import sys
input = sys.stdin.readline
import queue

n, m = map(int, input().split())
graph = [0 for _ in range(n)]
sx, sy = -1, -1

for i in range(n):
    graph[i] = list(map(int, input().replace("1", "-1").split()))
    if sx == -1 and sy == -1 and 2 in graph[i]:
        sx = i
        sy = graph[i].index(2)

q = queue.Queue()
q.put([sx, sy])
graph[sx][sy] = 0

while not q.empty():
    px, py = q.get()
    nlst = [[px - 1, py], [px + 1, py], [px, py - 1], [px, py + 1]]

    for nx, ny in nlst:
        if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == -1:
            q.put([nx, ny])
            graph[nx][ny] = graph[px][py] + 1

for i in graph:
    for j in i:
        print(j, end=" ")
    print()