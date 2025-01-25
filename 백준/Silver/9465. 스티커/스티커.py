import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())

    graph = [0] * 2
    dp = [[0] * (n + 2) for _ in range(2)]

    for i in range(2):
        graph[i] = list(map(int, input().split()))
    
    for i in range(2, n + 2):
        dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + graph[0][i - 2]
        dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + graph[1][i - 2]
    
    print(max(dp[0][n + 1], dp[1][n + 1]))