xa, ya, xb, yb, xc, yc = map(int, input().split())

def dist(h, t):
    return ((h[0] - t[0]) ** 2 + (h[1] - t[1]) ** 2) ** 0.5

dlst = [dist([xa, ya], [xb, yb]), dist([xc, yc], [xb, yb]), dist([xa, ya], [xc, yc])]
dlst.sort()

if ya == yb and yb == yc:
    print(-1.0)
elif ya != yb and yb != yc and (xa - xb) / (ya - yb) == (xb - xc) / (yb - yc):
    print(-1.0)
else:
    print(2 * (dlst[2] - dlst[0]))