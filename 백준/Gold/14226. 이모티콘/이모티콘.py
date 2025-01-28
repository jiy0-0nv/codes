from collections import deque

s = int(input())

graph = [[-1] * (s * 2 + 1) for _ in range(s * 2 + 1)]
graph[1][0] = 0
q = deque([(1, 0)])

while q:
    i, j = q.popleft()
    t = graph[i][j]
    
    if i + j == s or i - 1 == s:
        print(t + 1)
        break

    if i != j and graph[i][i] < 0:
        graph[i][i] = t + 1
        q.append((i, i))

    if i + j < s * 2 + 1 and graph[i + j][j] < 0:
        graph[i + j][j] = t + 1
        q.append((i + j, j))

    if i - 1 > 1 and graph[i - 1][j] < 0:
        graph[i - 1][j] = t + 1
        q.append((i - 1, j))