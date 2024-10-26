n = input()
l = len(n)
nl = [int(n[i]) for i in range(l)]

for i in range(l):
    if nl[i] < 4:
        if i > 0 and nl[i - 1] > 0:
            nl[i - 1] -= 1
            nl[i] += 10

for i in range(l):
    if nl[i] >= 7:
        if nl[i] > 7 and i < l - 1:
            nl[i + 1] += 10
        nl[i] = 7
    elif nl[i] >= 4:
        if nl[i] > 4 and i < l - 1:
            nl[i + 1] += 10
        nl[i] = 4
    else:
        if nl[i] > 0 and i < l - 1:
            nl[i + 1] += 10
        nl[i] = 0

ans = 0
for i in range(l):
    ans += nl[i] * (10 ** (l - 1 - i))

print(ans)