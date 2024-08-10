import sys
input = sys.stdin.readline

n, m = map(int, input().split())
ws = set()
wd = {}
wl = []

for _ in range(n):
    w = input().strip()
    if len(w) < m:
        continue
    elif w in ws:
        wd[w] += 1
    else:
        wd[w] = 0
        ws.add(w)
        wl.append(w)

for i in range(len(wl)):
    wl[i] = (wd[wl[i]], len(wl[i]), wl[i])

wl.sort(key=lambda x: (-x[0], -x[1], x[2]))

for w in wl:
    print(w[2])