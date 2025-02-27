n = int(input())
d = ' ' * (n - 2)

print('*' * n + ' ' * (2 * n - 3) + '*' * n)

for i in range(1, n - 1):
    print(' ' * i + '*', '*' + ' ' * (2 * n - 3 - i * 2) + '*', '*', sep=d)

print(' ' * (n - 1) + '*', '*', '*', sep=d)

for i in range(n - 2, 0, -1):
    print(' ' * i + '*', '*' + ' ' * (2 * n - 3 - i * 2) + '*', '*', sep=d)

print('*' * n + ' ' * (2 * n - 3) + '*' * n)