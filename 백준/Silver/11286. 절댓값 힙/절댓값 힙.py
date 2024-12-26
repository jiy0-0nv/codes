import sys
input = sys.stdin.readline

from queue import PriorityQueue
heap = PriorityQueue()

n = int(input())

for _ in range(n):
    x = int(input())
    if x:
        heap.put((abs(x), x))
    else:
        print(heap.get()[1] if heap.qsize() else 0)