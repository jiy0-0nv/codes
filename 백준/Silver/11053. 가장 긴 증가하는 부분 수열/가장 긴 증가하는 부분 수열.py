n = int(input())
al = list(map(int, input().split()))
ans = [1 for _ in range(n)]

for i in range(n):
    for j in range(i):
        if al[i] > al[j] and ans[i] < ans[j] + 1:
            ans[i] = ans[j] + 1

print(max(ans))