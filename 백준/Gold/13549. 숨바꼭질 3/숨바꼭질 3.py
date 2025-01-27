from collections import deque
import sys
input = sys.stdin.readline

n, k =map(int, input().split())

graph = [-1] * 200001

wq = deque()
wq.append(n)

tq = deque()
tq.append(n)

graph[n] = 0

while True:
    if graph[k] >= 0:
        print(graph[k])
        break

    if tq:
        tp = tq.popleft()
        x = tp * 2
        while x <= k * 2 and graph[x] < 0:
            graph[x] = graph[tp]
            wq.append(x)
            x *= 2

    else:
        wp = wq.popleft()
        if wp - 1 >= 0 and graph[wp - 1] < 0:
            graph[wp - 1] = graph[wp] + 1
            tq.append(wp - 1)
            wq.append(wp - 1)
        if wp + 1 <= k * 2 and graph[wp + 1] < 0:
            graph[wp + 1] = graph[wp] + 1
            tq.append(wp + 1)
            wq.append(wp + 1)