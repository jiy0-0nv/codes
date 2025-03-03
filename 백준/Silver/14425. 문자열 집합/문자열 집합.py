import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = set([input() for _ in range(n)])
count = 0

for _ in range(m):
    if input() in s:
        count += 1

print(count)