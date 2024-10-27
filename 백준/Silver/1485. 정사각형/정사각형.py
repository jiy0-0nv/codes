import sys
input = sys.stdin.readline

t = int(input())

def dst(x, y):
    return (x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2

for _ in range(t):
    a = tuple(map(int, input().split()))
    b = tuple(map(int, input().split()))
    c = tuple(map(int, input().split()))
    d = tuple(map(int, input().split()))
    p = [a, b, c, d]

    dlst = [dst(p[0], p[1]), dst(p[0], p[2]), dst(p[0], p[3]), dst(p[1], p[2]), dst(p[1], p[3]), dst(p[2], p[3])]
    dlst.sort()

    if dlst[0] == dlst[1] == dlst[2] == dlst[3] and dlst[4] == dlst[5]:
        print(1)
    else:
        print(0)