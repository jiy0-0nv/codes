import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    elif d >= max(r1, r2):
        if d > r1 + r2:
            print(0)
        elif d == r1 + r2:
            print(1)
        else:
            print(2)
    else:
        if d < abs(r1 - r2):
            print(0)
        elif d == abs(r1 - r2):
            print(1)
        else:
            print(2)