n = int(input())
l = len(bin(n)) - 2
ans = 0
for i in range(l):
    ans += (n & 1) * (3 ** i)
    n >>= 1
print(ans)