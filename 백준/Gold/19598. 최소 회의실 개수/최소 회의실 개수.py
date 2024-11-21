from heapq import heappush, heappop
import sys
input = sys.stdin.readline

n = int(input())
ml = [[0, 0] for _ in range(n)]
mr = []

for i in range(n):
    ml[i][0], ml[i][1] = map(int, input().split())

ml.sort()

for m in ml:
    if mr and mr[0] <= m[0]:
        heappop(mr)
    heappush(mr, m[1])

print(len(mr))