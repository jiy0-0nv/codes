n = int(input())
al = list(map(int, input().split()))
al.sort()
ans = -1
sub = 0

for i in range(n - 1):
    if (al[i + 1] - al[i]) // 2 > sub:
        sub = (al[i + 1] - al[i]) // 2
        ans = al[i] + sub
print(ans)