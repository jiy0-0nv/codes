import sys
input = sys.stdin.readline

n = int(input())
ans = list(input().strip())
l = len(ans)

for _ in range(n - 1):
    f = input().strip()
    for i in range(l):
        if ans[i] != '?' and ans[i] != f[i]:
            ans[i] = '?'

print(''.join(ans))