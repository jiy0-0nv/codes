n = int(input())

dp = [n] * (n + 1)
dp[0] = 0

for i in range(1, int(n ** (1/2) + 1)):
    dp[i ** 2] = 1
for i in range(1, n + 1):
    if dp[i] > 4:
        for j in range(1, int(i ** (1/2) + 1)):
            if dp[i] < 3:
                break
            dp[i] = min(dp[i], dp[i - j ** 2] + 1)

print(dp[n])