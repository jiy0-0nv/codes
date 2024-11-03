import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

m, n = map(int, input().split())
graph = [[0 for _ in range(n)] for _ in range(m)]

for i in range(m):
    s = input().strip()
    for j in range(n):
        if s[j] == '1':
            graph[i][j] = 1

ans = False

def dfs(a, b):
    graph[a][b] = 1
    global ans
    if ans:
        return
    if a == m - 1:
        ans = True
        return
    if graph[a + 1][b] == 0:
        dfs(a + 1, b)
    if a > 0 and graph[a - 1][b] == 0:
        dfs(a - 1, b)
    if b < n - 1 and graph[a][b + 1] == 0:
        dfs(a, b + 1)
    if b > 0 and graph[a][b - 1] == 0:
        dfs(a, b - 1)

for i in range(n):
    if not ans and graph[0][i] == 0:
        dfs(0, i)

if ans:
    print("YES")
else:
    print("NO")