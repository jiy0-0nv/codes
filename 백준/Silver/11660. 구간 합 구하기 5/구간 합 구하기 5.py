import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [0] * n

for i in range(n):
    graph[i] = list(map(int, input().split()))

gsum = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    lsum = 0
    for j in range(1, n + 1):
        lsum += graph[i - 1][j - 1]
        gsum[i][j] = gsum[i - 1][j] + lsum

for _ in range(m):
    i, j, x, y = map(int, input().split())
    print(gsum[x][y] - gsum[x][j - 1] - gsum[i - 1][y] + gsum[i - 1][j - 1])