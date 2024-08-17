import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
line = [[] for _ in range(n)]

for _ in range(n - 1):
    x, y = map(int, input().split())
    line[x - 1].append(y)
    line[y - 1].append(x)

prt = [0 for _ in range(n)]

def findparent(r, p):
    prt[r - 1] = p
    for i in line[r - 1]:
        if i != p and prt[i - 1] == 0:
            findparent(i, r)

findparent(1, -1)

for i in range(1, len(prt)):
    print(prt[i])