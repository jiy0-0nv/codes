import sys
input = sys.stdin.readline
s = set()
al = [i + 1 for i in range(20)]

m = int(input())
for _ in range(m):
    t = input().strip()
    if t == 'all':
        s = set(al)
    elif t == 'empty':
        s = set()
    else:
        t, x = t.split()
        x = int(x)
        if t == 'add':
            s.add(x)
        elif t == 'remove':
            s.discard(x)
        elif t == 'check':
            if x in s:
                print(1)
            else:
                print(0)
        elif t == 'toggle':
            if x in s:
                s.remove(x)
            else:
                s.add(x)