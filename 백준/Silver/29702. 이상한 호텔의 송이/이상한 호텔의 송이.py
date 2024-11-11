import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    while n > 0:
        l = len(bin(n)) - 2
        print(l, str(n - 2 ** (l - 1) + 1).zfill(18), sep="")
        n >>= 1