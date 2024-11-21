from collections import deque

n = int(input())
q = deque([i for i in range(1, n + 1)])

while len(q) > 1:
    q.popleft()
    c = q.popleft()
    q.append(c)

print(q.popleft())