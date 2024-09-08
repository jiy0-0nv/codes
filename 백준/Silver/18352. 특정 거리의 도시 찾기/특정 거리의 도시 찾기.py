import sys, heapq
input = sys.stdin.readline

n, m, k, x = map(int, input().split())
rd = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    rd[a].append(b)

d = [m for _ in range(n + 1)]
d[x] = 0

q = []
heapq.heappush(q, (0, x))

while q:
    dist, now = heapq.heappop(q)
    if d[now] < dist:
        continue
    for i in rd[now]:
        if dist + 1 < d[i]:
            d[i] = dist + 1
            heapq.heappush(q, (dist + 1, i))

zero = True
for i in range(1, n + 1):
    if d[i] == k:
        print(i)
        if zero:
            zero = False
if zero:
    print(-1)