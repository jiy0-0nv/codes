e = input()
nl = list(map(int, e.replace('+', ' ').replace('-', ' ').split()))

ans = nl[0]
n = 0

for i in e:
    if i == '+':
        n += 1
        ans += nl[n]
    elif i == '-':
        break

n += 1
for i in range(n, len(nl)):
    ans -= nl[i]

print(ans)