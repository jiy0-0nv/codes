import sys
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n)]

for i in range(n):
    graph[i] = list(map(int, input().split()))

for i in range(n):
    for j in range(n):
        for k in range(n):
            if graph[j][k] == 0 and graph[j][i] * graph[i][k] == 1:
                graph[j][k] = 1

for i in range(n):
    for j in graph[i]:
        print(j, end=" ")
    print()