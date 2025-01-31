import sys
input = sys.stdin.readline

sl = [0, 0, 0]

for _ in range(int(input())):
    s = input().strip()
    if s == '1/4':
        sl[0] += 1
    elif s == '1/2':
        sl[1] += 1
    elif s == '3/4':
        sl[2] += 1

ans = sl[2] + sl[1] // 2
sl[0] -= sl[2]
if sl[1] % 2:
    ans += 1
    sl[0] -= 2
if sl[0] > 0:
    ans += (sl[0] - 1) // 4 + 1

print(ans)