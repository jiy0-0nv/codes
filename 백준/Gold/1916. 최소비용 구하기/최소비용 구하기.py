import sys, heapq
input = sys.stdin.readline

n = int(input())
m = int(input())

graph = {}
ps = set()

for _ in range(m):
    s, e, c = map(int, input().split())
    if s not in ps:
        graph[s] = {}
        ps.add(s)
    if e not in ps:
        graph[e] = {}
        ps.add(e)
    if e not in graph[s] or c < graph[s][e]:
        graph[s][e] = c

s, e = map(int, input().split())
costs = [100000 * min(n - 1, m) for _ in range(n + 1)]
costs[s] = 0
queue = []
heapq.heappush(queue, [s, costs[s]])

while queue:
    p, c = heapq.heappop(queue)
    if c > costs[p]:
        continue
    for np, nc in graph[p].items():
        uc = costs[p] + nc
        if costs[np] > uc:
            costs[np] = uc
            heapq.heappush(queue, [np, uc])
        
print(costs[e])