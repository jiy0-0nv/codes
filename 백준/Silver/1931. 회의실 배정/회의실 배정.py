import sys
input = sys.stdin.readline

n = int(input())
ml = [0 for _ in range(n)]

for i in range(n):
    ml[i] = tuple(map(int, input().split()))

eml = sorted(ml, key = lambda x : (x[1], x[0]))

t = 0
ans = 0

for m in eml:
    if m[0] >= t:
        ans += 1
        t = m[1]
print(ans)