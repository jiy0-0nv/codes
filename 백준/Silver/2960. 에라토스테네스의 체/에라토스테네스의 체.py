n, k = map(int, input().split())

nl = [1 for _ in range(n + 1)]
nl[0] = 0
nl[1] = 0

for i in range(2, n + 1):
    if k * nl[i]:
        for j in range(1, n // i + 1):
            if nl[i * j]:
                nl[i * j] = 0
                k -= 1
                if k == 0:
                    print(i * j)
                    break