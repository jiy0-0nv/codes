n, k = map(int, input().split())
mt = list(map(int, input().split()))
for t in mt:
    n -= (t + 1) // 2

if n > 0:
    print("NO")
else:
    print("YES")