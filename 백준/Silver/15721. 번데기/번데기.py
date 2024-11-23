a = int(input())
t = int(input())
s = int(input())

ans = -1
i = 2
while t > 0:
    now = [0, 1, 0, 1] + [0] * i + [1] * i
    for j in now:
        if t == 0:
            break
        if j == s:
            t -= 1
        ans = (ans + 1) % a
    i += 1

print(ans)