from collections import deque

n, k = map(int, input().split())
q = deque([i for i in range(1, n + 1)])
i = 0

while q:
    i += 1
    t = q.popleft()
    if i % k:
        q.append(t)
    else:
        if i == k:
            print('<', end="")
        else:
            print(', ', end="")
        print(t, end="")
print('>')