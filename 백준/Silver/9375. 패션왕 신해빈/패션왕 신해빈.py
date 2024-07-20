import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    clothes = {}
    parts = set()
    pl = []
    for _ in range(n):
        c, p = input().split()
        if p in parts:
            clothes[p] += 1
        else:
            clothes[p] = 1
            parts.add(p)
            pl.append(p)
    count = 1
    for p in pl:
        count *= clothes[p] + 1
    print(count - 1)