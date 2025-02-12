n, k = map(int, input().split())
q = [i for i in range(1, n + 1)]
i = 0

print('<', end='')
for _ in range(n):
    i = (i + k - 1) % len(q)
    print(q.pop(i), end='')
    if q:
        print(', ', end='')
print('>')