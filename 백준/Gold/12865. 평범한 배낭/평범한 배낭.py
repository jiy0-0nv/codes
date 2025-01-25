import sys
input = sys.stdin.readline

n, k = map(int, input().split())
stuffs = [0] * n
dp = [[0] * (k + 1) for _ in range(n + 1)]

for i in range(n):
    stuffs[i] = tuple(map(int, input().split()))

for i in range(1, n + 1):
    for j in range(1, k + 1):
        if j < stuffs[i - 1][0]:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuffs[i - 1][0]] + stuffs[i - 1][1])

print(dp[n][k])