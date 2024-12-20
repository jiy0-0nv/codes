n = int(input())
a, b, c, d = 10, 10, -10, -10

for _ in range(n):
    ai, bi, ci, di = map(int, input().split())
    a = min(a, ai)
    b = min(b, bi)
    c = max(c, ci)
    d = max(d, di)
    print(2 * (c + d - a - b))