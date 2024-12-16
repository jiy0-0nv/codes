import sys
input = sys.stdin.readline

n = int(input())
nl = [int(input()) for _ in range(n)]

nl.sort()
e = n * 0.15
e = int(e) if e % 1 < 0.5 else int(e) + 1

if n - 2 * e:
    ans = sum(nl[e:n - e]) / (n - 2 * e)
    ans = int(ans) if ans % 1 < 0.5 else int(ans) + 1
else:
    ans = 0
print(ans)