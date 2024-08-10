import sys
input = sys.stdin.readline

ts = set()
tl = []
td = {}
tn = 0

for _ in range(1000000):
    t = input().strip()
    if not t:
        break
    elif t in ts:
        td[t] += 1
    else:
        ts.add(t)
        tl.append(t)
        td[t] = 1
    tn += 1

tl.sort()

for t in tl:
    print("%s %0.4f" % (t, td[t] / tn * 100))