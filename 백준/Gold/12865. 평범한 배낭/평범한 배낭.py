import sys
input = sys.stdin.readline

n, k = map(int, input().split())
stuffs = [0] * n
dp = [[0] * (n + 1) for _ in range(k + 1)]

for i in range(n):
    w, v = map(int, input().split())
    stuffs[i] = {'w': w, 'v': v}

for i in range(1, k + 1):
    for j in range(1, n + 1):
        if i < stuffs[j - 1]['w']:
            dp[i][j] = dp[i][j - 1]
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - stuffs[j - 1]['w']][j - 1] + stuffs[j - 1]['v'])

print(dp[k][n])