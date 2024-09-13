n = int(input())

d = [2019, 1]
w = 6
ans = 0

m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

while True:
    if d[0] == n and d[1] == 12:
        break
    md = m[d[1] - 1]
    if d[1] == 2:
        if d[0] % 400 == 0:
            md = 29
        elif d[0] % 100 != 0 and d[0] % 4 == 0:
            md = 29
    w = (w + md) % 7

    if w == 4:
        ans += 1

    d[1] += 1
    if d[1] == 13:
        d[0] += 1
        d[1] = 1
    
print(ans)