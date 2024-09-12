import sys
input = sys.stdin.readline

n = int(input())
graph = [[0 for _ in range(26)] for _ in range(26)]
for i in range(26):
    graph[i][i] = 1

for _ in range(n):
    str = input()
    graph[ord(str[0]) - ord('a')][ord(str[5]) - ord('a')] = 1

for c in range(26):
    for a in range(26):
        for b in range(26):
            if graph[a][c] and graph[c][b]:
                graph[a][b] = 1

m = int(input())

for _ in range(m):
    str = input()
    if graph[ord(str[0]) - ord('a')][ord(str[5]) - ord('a')] == 1:
        print('T')
    else:
        print('F')