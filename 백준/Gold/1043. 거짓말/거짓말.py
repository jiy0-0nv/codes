import sys
input = sys.stdin.readline

n, m = map(int, input().split())
tl = list(map(int, input().split()))
if tl[0]:
    tl = tl[1:]
    ts = set(tl)
else:
    tl = []
    ts = set()

pl = [False] * m
ans = m

for i in range(m):
    pl[i] = set(list(map(int, input().split()))[1:])

for _ in range(m):
    for i in range(m):
        if pl[i] and ts & pl[i]:
            ts = ts.union(pl[i])
            ans -= 1
            pl[i] = False

print(ans)