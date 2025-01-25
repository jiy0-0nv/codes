import sys
input = sys.stdin.readline

n, k = map(int, input().split())
stuffs = [0] * n
dp = [[0] * (n + 1) for _ in range(k + 1)]

for i in range(n):
    stuffs[i] = tuple(map(int, input().split()))

for i in range(1, k + 1):
    for j in range(1, n + 1):
        if i < stuffs[j - 1][0]:
            dp[i][j] = dp[i][j - 1]
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - stuffs[j - 1][0]][j - 1] + stuffs[j - 1][1])

print(dp[k][n])