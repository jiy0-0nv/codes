import sys
input = sys.stdin.readline

n = int(input())
total = 0
skip = 0 #건너뜀으로써 절약되는 거리
ppx, ppy = 0, 0 #전전 체크포인트
px, py = 0, 0 #직전 체크포인트

def md(a, b, c, d):
    return abs(a - b) + abs(c - d)

for i in range(n):
    x, y = map(int, input().split())
    if i > 0:
        total += md(px, x, py, y)
    if i > 1:
        ns = md(ppx, px, ppy, py) + md(px, x, py, y) - md(ppx, x, ppy, y)
        skip = max(skip, ns)
    ppx, ppy = px, py
    px, py = x, y

print(total - skip)