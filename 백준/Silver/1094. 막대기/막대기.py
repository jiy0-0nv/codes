x = int(input())
ans = 1
l = 64
while l > x:
    if (l >> 1) < x:
        x -= (l >> 1)
        ans += 1
    l >>= 1
print(ans)