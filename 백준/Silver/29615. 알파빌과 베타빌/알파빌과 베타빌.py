n, m = map(int, input().split())
nl = list(map(int, input().split()))
ml = set(map(int, input().split()))
ans = 0
for i in range(m):
    if nl[i] not in ml:
        ans += 1
print(ans)