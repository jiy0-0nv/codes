import sys
input = sys.stdin.readline

n, m = map(int, input().split())
ns = set()
nm = []

for _ in range(n):
    ns.add(input().strip())
for _ in range(m):
    p = input().strip()
    if p in ns:
        nm.append(p)

print(len(nm))
nm.sort()
for i in nm:
    print(i)