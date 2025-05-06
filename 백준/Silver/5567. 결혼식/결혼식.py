import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
lst = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    lst[a].append(b)
    lst[b].append(a)

s = set(lst[1])

for i in lst[1]:
    s |= set(lst[i])

s.discard(1)
print(len(s))