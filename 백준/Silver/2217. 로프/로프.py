import sys
input = sys.stdin.readline

n = int(input())
rl = [0 for _ in range(n)]

for i in range(n):
    rl[i] = int(input())

rl.sort()
ans = 0

for i in range(n):
    if ans <= rl[i] * (n - i):
        ans = rl[i] * (n - i)

print(ans)