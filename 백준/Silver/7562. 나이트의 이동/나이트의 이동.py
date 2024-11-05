import sys
input = sys.stdin.readline
import queue

t = int(input())

def bfs(x, y):
    q = queue.Queue()
    q.put([x, y])
    
    graph[x][y] = 0
    
    while q.qsize() > 0:
        px, py = q.get()
        if px == ex and py == ey:
            return graph[px][py]

        plst = [[px + 1, py + 2], [px + 2, py + 1],
                [px + 2, py - 1], [px + 1, py - 2],
                [px - 1, py - 2], [px - 2, py - 1],
                [px - 2, py + 1], [px - 1, py + 2]]
        
        for ix, iy in plst:
            if 0 <= ix < l and 0 <= iy < l and graph[ix][iy] == -1:
                q.put([ix, iy])
                graph[ix][iy] = graph[px][py] + 1

for _ in range(t):
    l = int(input())
    graph = [[-1] * l for _ in range(l)]
    sx, sy = map(int, input().split())
    ex, ey = map(int, input().split())
    print(bfs(sx, sy))