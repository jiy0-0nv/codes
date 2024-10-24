import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
x = int(input())

for i in range(2, x + 1):
    if x % i == 0:
        x //= i
        for j in range(len(a)):
            if a[j] != 0 and a[j] % i == 0:
                a[j] = 0
                n -= 1

print(sum(a) / n)