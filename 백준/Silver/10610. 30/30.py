nl = [int(n) for n in input()]
nl.sort(reverse=True)
ans = ''
if nl[len(nl) - 1] or sum(nl) % 3:
    ans = -1
else:
    for n in nl:
        ans += str(n)
print(ans)