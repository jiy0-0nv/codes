import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    t = input()
    s = 0
    for i in t:
        if i == '(':
            s += 1
        elif i == ')':
            s -= 1
        if s < 0:
            break
    if s == 0:
        print('YES')
    else:
        print('NO')