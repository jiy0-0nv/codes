n = int(input())
m = int(input())
s = input()

i, x, ans = 2, 0, 0

while i < m:
    if s[i - 2:i + 1] == 'IOI':
        x += 1
        i += 2
    else:
        if x >= n:
            ans += x - n + 1
            i -= 2
        x = 0
        i += 1
if x >= n:
    ans += x - n + 1

print(ans)