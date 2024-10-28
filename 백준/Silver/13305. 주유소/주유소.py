import sys
input = sys.stdin.readline
n = int(input())
rl = list(map(int, input().split()))
pl = list(map(int, input().split()))
p = pl[0]
ans = pl[0] * rl[0]

for i in range(1, n - 1):
    p = min(p, pl[i])
    ans += p * rl[i]

print(ans)