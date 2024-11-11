n = int(input())

dp = [0] * 15
dp[0] = 3
dp[1] = 11
for i in range(2, n // 2):
    dp[i] = 4 * dp[i - 1] - dp[i - 2]

if n % 2 == 0:
    print(dp[n // 2 - 1])
else:
    print(0)