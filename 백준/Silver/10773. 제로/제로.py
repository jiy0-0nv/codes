import sys
input = sys.stdin.readline
from collections import deque

k = int(input())
nl = deque([])
for _ in range(k):
    n = int(input())
    if n:
        nl.append(n)
    else:
        nl.pop()
print(sum(nl))