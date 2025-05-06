import sys
input = sys.stdin.readline

n, m = map(int, input().split())
rl = [list(map(int, list(input().strip()))) for _ in range(n)]
ans = 1

for i in range(n):
    for j in range(m):
        x = rl[i][j]
        for k in range(j + 1, m):
            if rl[i][k] == x and i + k - j < n and rl[i + k - j][j] == x and rl[i + k - j][k] == x:
                ans = max(ans, (k - j + 1) ** 2)
print(ans)