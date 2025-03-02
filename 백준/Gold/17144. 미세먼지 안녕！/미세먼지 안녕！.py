import sys
input = sys.stdin.readline

r, c, t = map(int, input().split())
ar = 0
drt = [[-1, 0], [1, 0], [0, -1], [0, 1]]

graph = [list(map(int, input().split())) for _ in range(r)]
for i in range(r):
    if graph[i][0] == -1:
        ar = i
        graph[i][0] = 0
        graph[i + 1][0] = 0
        break

for _ in range(t):

    ngp = [row[:] for row in graph]
    
    for i in range(r):
        for j in range(c):
            if graph[i][j]:
                count = 0
                for x, y in drt:
                    if 0 <= i + x < r and 0 <= j + y < c and not (j + y == 0 and ar <= i + x <= ar + 1):
                        ngp[i + x][j + y] += graph[i][j] // 5
                        count += 1
                ngp[i][j] -= (graph[i][j] // 5) * count
        
    for i in range(r):
        for j in range(c):
            if (i == 0 or i == r - 1) and j < c - 1:
                graph[i][j] = ngp[i][j + 1]
            elif (i < ar and j == c - 1) or (i > ar + 1 and j == 0):
                graph[i][j] = ngp[i + 1][j]
            elif (0 < i < ar and j == 0) or (i > ar + 1 and j == c - 1):
                graph[i][j] = ngp[i - 1][j]
            elif (i == ar or i == ar + 1) and j > 0:
                graph[i][j] = ngp[i][j - 1]
            else:
                graph[i][j] = ngp[i][j]

ans = 0
for r in graph:
    ans += sum(r)
print(ans)