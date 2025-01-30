n, l = map(int, input().split())
hl = list(map(int, input().split()))
hl.sort()
ans = l

for i in range(n):
    if i + l < hl[i]:
        ans += i
        break
    elif i == n - 1:
        ans += n

print(ans)