import sys
input = sys.stdin.readline

n, k = map(int, input().split())
stuffs = [0] * n
dp = [0] * (k + 1)

for i in range(n):
    stuffs[i] = tuple(map(int, input().split()))

for w, v in stuffs:
    for i in range(k, w - 1, -1):
        dp[i] = max(dp[i], dp[i - w] + v)

print(dp[k])