n = int(input())
a = list(map(int, input().split()))

da = [1 for _ in range(n)]
ans = 1

for i in range(n):
    t = a[i]
    for j in range(i):
        if t < a[j] and da[j] + 1 > da[i]:
            da[i] = da[j] + 1
    if da[i] > ans:
        ans = da[i]

print(ans)