import sys
input = sys.stdin.readline
from collections import deque

queue = deque([])
n = int(input())

for _ in range(n):
    c = input().strip()
    if c[:2] == 'pu':
        queue.append(int(c[5:]))
    elif c[0] == 'p':
        print(queue.popleft() if queue else -1)
    elif c[0] == 's':
        print(len(queue))
    elif c[0] == 'e':
        print(0 if queue else 1)
    elif c[0] == 'f':
        print(queue[0] if queue else -1)
    else:
        print(queue[-1] if queue else -1)