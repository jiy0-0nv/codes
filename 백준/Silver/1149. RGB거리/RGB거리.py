import sys
input = sys.stdin.readline

n = int(input())
rgb = [0 for _ in range(n)]

for i in range(n):
    rgb[i] = list(map(int, input().split()))

cost = rgb[0]

for j in range(1, n):
    for i in range(3):
        rgb[j][i] += min(cost[(i + 1) % 3], cost[(i + 2) % 3])
    cost = rgb[j]

print(min(cost))
