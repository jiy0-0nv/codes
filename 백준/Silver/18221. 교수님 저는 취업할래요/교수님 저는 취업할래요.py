import sys
input = sys.stdin.readline

n = int(input())
p = [0, 0]
s = [0, 0]
c = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    l = list(map(int, input().split()))
    for j in range(n):
        if l[j] == 1:
            c[i][j] = 1
        elif l[j] == 2:
            s[0] = i
            s[1] = j
        elif l[j] == 5:
            p[0] = i
            p[1] = j

if (p[0] - s[0]) ** 2 + (p[1] - s[1]) ** 2 < 25:
    print(0)
else:
    f = 0
    for i in range(min(p[0], s[0]), max(p[0], s[0]) + 1):
        for j in range(min(p[1], s[1]), max(p[1], s[1]) + 1):
            if c[i][j]:
                f += 1
                if f == 3:
                    break
        if f == 3:
            break
    if f == 3:
        print(1)
    else:
        print(0)