nl = list(map(int, input().split()))
nl.sort()
l = len(nl)
s = int(input())

ans = []

for i in range(l - 1):
    if nl[i] > s or (i > 0 and nl[i - 1] == nl[i]):
        break
    for j in range(i + 1, l):
        a = nl[i] + nl[j]
        if a > s:
            break
        elif a == s:
            ans.append((nl[i], nl[j]))
            break

for a in ans:
    print(a[0], a[1])
print(len(ans))