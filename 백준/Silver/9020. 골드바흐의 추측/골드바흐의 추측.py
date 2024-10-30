import sys
input = sys.stdin.readline

t = int(input())

def check(x):
    for i in range(2, int(x ** 0.5 + 1)):
        if x % i == 0:
            return False
    return True

for _ in range(t):
    n = int(input())
    a = n // 2 if n % 2 == 0 else n // 2 + 1
    b = n // 2
    while a < n:
        if check(a) and check(b):
            print(b, a)
            break
        a += 1
        b -= 1