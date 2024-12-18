import sys
input = sys.stdin.readline

n = int(input())
pl = [0] * (3 * n)

for i in range(3 * n):
    x, y = map(int, input().split())
    pl[i] = (x, y, i + 1)

pl.sort()

for i in range(n):
    print(pl[3 * i][2], pl[3 * i + 1][2], pl[3 * i + 2][2])