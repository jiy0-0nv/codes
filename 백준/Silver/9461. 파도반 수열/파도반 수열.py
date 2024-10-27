import sys
input = sys.stdin.readline

p = [0 for _ in range(101)]
p[1] = 1
p[2] = 1
p[3] = 1
p[4] = 2
p[5] = 2

t = int(input())
for _ in range(t):
    n = int(input())
    if p[n] != 0:
        print(p[n])
    else:
        for i in range(6, n + 1):
            if p[i] == 0:
                p[i] = p[i - 5] + p[i - 1]
        print(p[n])