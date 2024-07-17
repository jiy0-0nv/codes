import sys
input = sys.stdin.readline

n, k = map(int, input().split())
wheel = ['?' for _ in range(n)]
i = 0
chrs = set()

for _ in range(k):
    r, c = input().split()
    i += int(r)
    i %= n
    if wheel[i] == '?':
        if c in chrs:
            wheel = False
            break
        else:
            wheel[i] = c
            chrs.add(c)
    elif wheel[i] != c:
        wheel = False
        break

for _ in range(n):
    if not wheel:
        print('!')
        break
    print(wheel[i], end="")
    i = i - 1 if i != 0 else n - 1