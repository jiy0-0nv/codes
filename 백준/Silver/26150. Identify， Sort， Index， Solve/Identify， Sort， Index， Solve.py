import sys
input = sys.stdin.readline

n = int(input())
sl = [0] * n

for i in range(n):
    a, b, c = input().split()
    sl[i] = (int(b), a[int(c) - 1].upper())

sl.sort()
for s in sl:
    print(s[1], end='')