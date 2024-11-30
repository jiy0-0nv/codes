n = int(input())
nlst = list(map(int, input().split()))
ans = 0
nsum = sum(nlst)

for i in range(n - 1):
    nsum -= nlst[i]
    ans += nlst[i] * nsum

print(ans)