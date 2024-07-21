n = int(input())

m = [0, 1, 2]

for i in range(3, n + 1):
    m[i % 3] = (m[(i - 1) % 3] % 10007 + m[(i - 2) % 3] % 10007) % 10007

print(m[n % 3])