t = int(input())

for _ in range(t):
    n = int(input())
    d = [1, 2, 4]
    for i in range(4, n + 1):
        d[(i - 1) % 3] = sum(d)
    print(d[(n - 1) % 3])