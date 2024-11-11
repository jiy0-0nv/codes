n = int(input())
a, b = map(int, input().split())
t = a + b
if a + b > n:
    t = 2 * n - a - b
print(2 ** t - 1 << (n - t))