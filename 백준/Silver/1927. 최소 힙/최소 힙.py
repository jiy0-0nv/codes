import heapq
import sys
input = sys.stdin.readline

n = int(input())
hp = []

for _ in range(n):
    i = int(input())
    if i != 0:
        heapq.heappush(hp, i)
    elif len(hp) == 0:
        print(0)
    else:
        print(heapq.heappop(hp))