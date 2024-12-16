n = int(input())
sl = list(map(int, input().split()))

nl = [False] * n
m = -1
for t in sl:
    if not nl[m] or nl[m][0] != t:
        m += 1
        nl[m] = [t, 1]
    else:
        nl[m][1] += 1

l, r, fn = 0, 0, 0
fl = [0] * 10
ans = 0
t = 0
while r < m + 1:
    if not fl[nl[r][0]]:
        fn += 1
    fl[nl[r][0]] += 1
    t += nl[r][1]

    while fn > 2:
        fl[nl[l][0]] -= 1
        t -= nl[l][1]
        if not fl[nl[l][0]]:
            fn -= 1
        l += 1
    ans = max(ans, t)
    r += 1

print(ans)