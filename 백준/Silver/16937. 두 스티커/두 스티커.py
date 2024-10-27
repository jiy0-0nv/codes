import sys
input = sys.stdin.readline

h, w = map(int, input().split())
n = int(input())
s = [[0, 0] for _ in range(n)]

for i in range(n):
    s[i][0], s[i][1] = map(int, input().split())

ans = 0

for i in range(n - 1):
    for j in range(i + 1, n):
        c = [[s[i][0], s[i][1], s[j][0], s[j][1]],
             [s[i][1], s[i][0], s[j][0], s[j][1]],
             [s[i][0], s[i][1], s[j][1], s[j][0]],
             [s[i][1], s[i][0], s[j][1], s[j][0]]]
        for k in c:
            if (k[0] + k[2] <= h or k[1] + k[3] <= w) and k[0] <= h and k[1] <= w and k[2] <= h and k[3] <= w:
                ans = max(ans, k[0] * k[1] + k[2] * k[3])
                break

print(ans)