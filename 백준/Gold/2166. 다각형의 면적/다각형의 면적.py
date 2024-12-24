import sys
input = sys.stdin.readline

n = int(input())
xl = [0] * (n + 1)
yl = [0] * (n + 1)

for i in range(n):
    xl[i], yl[i] = map(int, input().split())

xl[n], yl[n] = xl[0], yl[0]

ans = 0
for i in range(n):
    ans += xl[i] * yl[i + 1]
    ans -= xl[i + 1] * yl[i]

print(abs(ans / 2))