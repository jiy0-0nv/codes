import sys
input = sys.stdin.readline

k = int(input())
c = int(input())

for _ in range(c):
    m, n = map(int, input().split())
    ans = 0
    for i in range(max(m, n), k + 1):
        if 0 <= n - m <= k - i + 1 or 0 <= m - n <= k - i + 2:
            ans = 1
            break
    print(ans)