import sys
input = sys.stdin.readline

n = int(input())
lst = [0] * n

for i in range(n):
    lst[i] = int(input())

lst.sort(reverse=True)
ans = 0
for i in range(n):
    if i % 3 < 2:
        ans += lst[i]
print(ans)