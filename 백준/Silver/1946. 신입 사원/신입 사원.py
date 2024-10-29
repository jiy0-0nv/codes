import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    ans = n
    nl = [0 for _ in range(n)]
    for _ in range(n):
        a, b = map(int, input().split())
        nl[a - 1] = b
    m = nl[0]
    for p in nl:
        if m < p:
            ans -= 1
        else:
            m = p
    print(ans)