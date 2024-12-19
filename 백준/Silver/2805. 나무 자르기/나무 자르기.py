n, m = map(int, input().split())
hl = list(map(int, input().split()))

hl.sort(reverse=True)
hl.append(0)
ans = -1

for i in range(1, n + 1):
    if m <= i * (hl[i - 1] - hl[i]):
        ans = hl[i - 1] - ((m - 1) // i + 1)
        break
    else:
        m -= i * (hl[i - 1] - hl[i])

print(ans)