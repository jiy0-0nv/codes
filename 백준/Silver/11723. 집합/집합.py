import sys
input = sys.stdin.readline

s = 0
n = 2 ** 20 - 1
m = int(input())

for _ in range(m):
    t = input().strip()
    if t == 'all':
        s = n
    elif t == 'empty':
        s = 0
    else:
        t, x = t.split()
        x = int(x)
        if t == 'add':
            s |= (1 << (x - 1))
        elif t == 'remove':
            s &= ((1 << (x - 1)) ^ n)
        elif t == 'check':
            print((s >> (x - 1)) & 1)
        elif t == 'toggle':
            s ^= (1 << (x - 1))