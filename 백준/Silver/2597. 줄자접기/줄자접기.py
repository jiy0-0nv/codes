e = int(input())
r1, r2 = map(int, input().split())
b1, b2 = map(int, input().split())
y1, y2 = map(int, input().split())
pl = [r1, r2, b1, b2, y1, y2, 0, e]

for s in range(0, 5, 2):
    if pl[s] != pl[s + 1]:
        m = (pl[s] + pl[s + 1]) / 2
        for i in range(s + 2, 8):
            if pl[i] > m:
                pl[i] = m * 2 - pl[i]
        pl[6] = min(pl[6], pl[7])
        pl[7] = m

print(pl[7] - pl[6])