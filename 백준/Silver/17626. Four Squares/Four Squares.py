n = int(input())
m = [False] * 50001

for i in range(1, int(n ** (1/2) + 1)):
    m[i ** 2] = True

ans = 4
for i in range(int(n ** 0.5), 0, -1):
    if m[n]:
        ans = 1
        break
    if m[n - i ** 2]:
        ans = 2
        break
    else:
        for j in range(int((n - i ** 2) ** (1/2) + 1), 0, -1):
            if m[n - i ** 2 - j ** 2]:
                ans = 3

print(ans)