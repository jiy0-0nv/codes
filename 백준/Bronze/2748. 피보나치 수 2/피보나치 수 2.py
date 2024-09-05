n = int(input())

f = [0, 1, 1]

for i in range(n + 1):
    if i < 3:
        continue
    f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3]

print(f[n % 3])