n, k = map(int, input().split())
al = list(map(int, input().split()))

ps = 0
ss = set([0])
sd = {0:1}
ans = 0

for i in range(n):
    ps += al[i]
    if ps - k in ss:
        ans += sd[ps - k]
    if ps in ss:
        sd[ps] += 1
    else:
        ss.add(ps)
        sd[ps] = 1

print(ans)