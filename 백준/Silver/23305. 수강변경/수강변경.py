n = int(input())
al = list(map(int, input().split()))
bl = list(map(int, input().split()))
al.sort()
bl.sort()
ans = 0
ai, bi = 0, 0
while True:
    if ai == n or bi == n:
        ans += n - ai
        break
    if al[ai] == bl[bi]:
        ai += 1
        bi += 1
    elif al[ai] > bl[bi]:
        bi += 1
    else:
        ans += 1
        ai += 1
print(ans)