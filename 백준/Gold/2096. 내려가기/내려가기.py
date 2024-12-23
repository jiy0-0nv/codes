import sys
input = sys.stdin.readline

maxdp = [[0, 0, 0], [0, 0, 0]]
mindp = [[0, 0, 0], [0, 0, 0]]

n = int(input())

for _ in range(1, n + 1):
    a, b, c = map(int, input().split())
    maxdp[1][0] = max(maxdp[0][0], maxdp[0][1]) + a
    maxdp[1][1] = max(maxdp[0]) + b
    maxdp[1][2] = max(maxdp[0][1], maxdp[0][2]) + c
    mindp[1][0] = min(mindp[0][0], mindp[0][1]) + a
    mindp[1][1] = min(mindp[0]) + b
    mindp[1][2] = min(mindp[0][1], mindp[0][2]) + c

    for i in range(3):
        maxdp[0][i] = maxdp[1][i]
        mindp[0][i] = mindp[1][i]

print(max(maxdp[0]), min(mindp[0]))