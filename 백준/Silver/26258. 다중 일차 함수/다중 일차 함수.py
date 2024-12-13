import sys
input = sys.stdin.readline
from bisect import bisect_left

n = int(input())
xl = [0] * n
yl = [0] * n
for i in range(n):
    xl[i], yl[i] = map(int, input().split())
q = int(input())

for _ in range(q):
    k = float(input())
    i = bisect_left(xl, k)
    if yl[i - 1] < yl[i]:
        print(1)
    elif yl[i - 1] > yl[i]:
        print(-1)
    else:
        print(0)