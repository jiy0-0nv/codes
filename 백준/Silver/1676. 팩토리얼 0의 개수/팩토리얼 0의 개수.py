n = int(input())
c = [0, 0]
for i in range(2, n + 1):
    while i % 10 == 0:
        c[0] += 1
        c[1] += 1
        i //= 10
    while i % 2 == 0:
        c[0] += 1
        i //= 2
    while i % 5 == 0:
        c[1] += 1
        i //= 5

print(min(c))