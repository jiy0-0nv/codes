import sys
input = sys.stdin.readline

n = int(input())
t = [0 for _ in range(n)]

for i in range(n):
    x, y, v = map(int, input().split())
    t[i] = ((x ** 2 + y ** 2) / v ** 2, i + 1)

t.sort()
for i in t:
    print(i[1])