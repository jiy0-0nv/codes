import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    for i in range(38):
        if not n:
            break
        if n & 1:
            ans += 3 ** i
        n >>= 1
    print(ans)