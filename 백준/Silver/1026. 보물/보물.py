n = int(input())
al = list(map(int, input().split()))
bl = list(map(int, input().split()))

al.sort()
bl.sort(reverse=True)

ans = 0
for i in range(n):
    ans += al[i] * bl[i]

print(ans)