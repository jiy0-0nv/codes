import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    q = list(input().split('+'))
    if len(q) == 1:
        print('skipped')
    else:
        print(int(q[0]) + int(q[1]))