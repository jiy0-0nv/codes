import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
graph = [0] * n

for i in range(n):
    graph[i] = list(map(int, input().split()))

def slicing(x, y, l, w, b):
    xl = [[x, y],
           [x, y+l],
           [x+l, y],
           [x+l, y+l]]
    for x1, y1 in xl:
        s = 0
        for i in graph[x1:x1+l]:
            s += sum(i[y1:y1+l])
        if s == 0:
            w += 1
        elif s == l ** 2:
            b += 1
        else:
            w, b = slicing(x1, y1, l//2, w, b)
    return w, b
            
sp = sum(sum(graph, []))

if sp == n ** 2:
    print(0)
    print(1)
elif sp == 0:
    print(1)
    print(0)
else:
    w, b = slicing(0, 0, n // 2, 0, 0)
    print(w)
    print(b)
