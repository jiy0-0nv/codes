import sys
input = sys.stdin.readline

w, h, x, y, p = map(int, input().split())
r = h / 2.0
ans = 0

for _ in range(p):
    a, b = map(float, input().split())
    if y <= b <= y + h:
        if x <= a <= x + w or min(abs(x - a), abs(x + w - a)) ** 2.0 + (y + r - b) ** 2.0 <= r ** 2:
            ans += 1

print(ans)