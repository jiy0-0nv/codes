import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    gcd = 1
    for i in range(2, min(a, b)):
        while a % i == 0 and b % i == 0:
            a //= i
            b //= i
            gcd *= i
        if i > min(a, b):
            break
    print(a * b * gcd)