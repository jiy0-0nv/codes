from collections import deque

idx = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]

while True:
    w, h = map(int, input().split())
    if w == 0:
        break
    else:
        graph = [0] * h
        q = deque()
        ans = 0

        for i in range(h):
            graph[i] = list(map(int, input().split()))
        for i in range(h):
            for j in range(w):
                if graph[i][j]:
                    ans += 1
                    q.append((i, j))
                    while q:
                        x, y = q.pop()
                        graph[x][y] = 0
                        for dx, dy in idx:
                            if h > x + dx >= 0 and w > y + dy >= 0 and graph[x + dx][y + dy]:
                                q.append((x + dx, y + dy))
        print(ans)