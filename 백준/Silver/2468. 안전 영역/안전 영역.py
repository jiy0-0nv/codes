from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
D = [(-1, 0), (0, -1), (0, 1), (1, 0)]

q = deque()
ans = 0

for h in range(101):
    visited = [[False] * n for _ in range(n)]
    count = 0

    for i in range(n):
        for j in range(n):
            if graph[i][j] > h and not visited[i][j]:
                count += 1
                visited[i][j] = True
                q.append((i, j))
                while q:
                    x, y = q.popleft()
                    for dx, dy in D:
                        xi, yi = x + dx, y + dy
                        if 0 <= xi < n and 0 <= yi < n and graph[xi][yi] > h and not visited[xi][yi]:
                            visited[xi][yi] = True
                            q.append((xi, yi))

    if not count:
        break
    ans = max(count, ans)

print(ans)