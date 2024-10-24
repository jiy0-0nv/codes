import sys
input = sys.stdin.readline

t = int(input())

def gcd(a, b):
    for i in range(min(a, b), 1, -1):
        if a % i == 0 and b % i == 0:
            return i
    return 1

for _ in range(t):
    ans = 0
    nl = list(map(int, input().split()))
    n = nl[0]
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            ans += gcd(nl[i], nl[j])
    print(ans)