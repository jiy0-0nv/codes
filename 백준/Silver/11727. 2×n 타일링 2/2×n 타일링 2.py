n = int(input())
a = n % 2
b = n // 2
ans = 0

def cb(n, r):
    c = 1
    for i in range(n - r + 1, n + 1):
        c *= i
    for i in range(1, r + 1):
        c //= i
    return c % 10007

for _ in range(n // 2 + 1):
    ans += (cb(a + b, a) * ((2 ** b) % 10007)) % 10007
    ans %= 10007
    a += 2
    b -= 1

print(ans)