a = input()
b = input()
al, bl = len(a), len(b)

dp = [[0 for _ in range(al + 1)] for _ in range(bl + 1)]

for i in range(1, bl + 1):
    for j in range(1, al + 1):
        if a[j - 1] == b[i - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[bl][al])