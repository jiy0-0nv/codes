import sys, heapq
input = sys.stdin.readline

n, d = map(int, input().split())

graph = {0: {d: d}}
ps = set([0, d])

for _ in range(n):
    s, e, l = map(int, input().split())
    if e > d or e - s <= l:
        continue
    if s not in ps:
        ps.add(s)
        graph[s] = {}
    if e not in ps:
        ps.add(e)
        graph[e] = {}
        
    if e not in graph[s] or graph[s][e] > l:
        graph[s][e] = l

pl = list(ps)
pl.sort()

for i in range(1, len(pl)):
    if pl[i] not in graph[pl[i - 1]]:
        graph[pl[i - 1]][pl[i]] = pl[i] - pl[i - 1]

dstl = {p: p for p in pl}
queue = []
heapq.heappush(queue, [dstl[0], 0])

while queue:
    curd, curp = heapq.heappop(queue)

    if curp == d or dstl[curp] < curd:
        continue

    for newp, newd in graph[curp].items():
        dst = curd + newd
        if dst <= dstl[newp]:
            dstl[newp] = dst
            heapq.heappush(queue, [dst, newp])

print(dstl[d])