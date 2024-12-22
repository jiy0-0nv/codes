from queue import PriorityQueue
import sys
input = sys.stdin.readline

pq = PriorityQueue()
n = int(input())

for _ in range(n):
    x = int(input())
    if not x:
        if pq.qsize():
            print(100000 - pq.get())
        else:
            print(0)
    else:
        pq.put(100000 - x)