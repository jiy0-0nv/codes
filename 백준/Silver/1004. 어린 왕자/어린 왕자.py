import sys
input = sys.stdin.readline

t = int(input())

def check(a, b, r):
    d = ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5
    if d > r:
        return False
    else:
        return True

for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    ans = 0

    for _ in range(n):
        cx, cy, r = map(int, input().split())
        c1 = check([x1, y1], [cx, cy], r)
        c2 = check([x2, y2], [cx, cy], r)
        if (not (c1 and c2)) and (c1 or c2):
            ans += 1
            
    print(ans)