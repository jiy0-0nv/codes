n, l, k = map(int, input().split())
s1, s2 = 0, 0

for _ in range(n):
    a, b = map(int, input().split())
    if b <= l:
        s2 += 1
    elif a <= l:
        s1 += 1

ans = min(s2, k) * 140 + min(s1, k - min(s2, k)) * 100

print(ans)
