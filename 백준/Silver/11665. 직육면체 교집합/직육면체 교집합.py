import sys
input = sys.stdin.readline

n = int(input())
sl = [[0, 0, 0, 0, 0, 0, 0, 0] for _ in range(n)]

for i in range(n):
    pl = list(map(int, input().split()))
    sl[i][0] = min(pl[0], pl[3])
    sl[i][1] = min(pl[1], pl[4])
    sl[i][2] = min(pl[2], pl[5])
    sl[i][3] = max(pl[0], pl[3])
    sl[i][4] = max(pl[1], pl[4])
    sl[i][5] = max(pl[2], pl[5])

mnp = sl[0][:3]
mxp = sl[0][3:]

for i in range(1, n):
    mnp[0] = max(mnp[0], sl[i][0])
    mnp[1] = max(mnp[1], sl[i][1])
    mnp[2] = max(mnp[2], sl[i][2])
    mxp[0] = min(mxp[0], sl[i][3])
    mxp[1] = min(mxp[1], sl[i][4])
    mxp[2] = min(mxp[2], sl[i][5])
    if mnp[0] >= mxp[0] or mnp[1] >= mxp[1] or mnp[2] >= mxp[2]:
        break

if mnp[0] >= mxp[0] or mnp[1] >= mxp[1] or mnp[2] >= mxp[2]:
    print(0)
else:
    print((mxp[0] - mnp[0]) * (mxp[1] - mnp[1]) * (mxp[2] - mnp[2]))