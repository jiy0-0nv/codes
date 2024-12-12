import sys
input = sys.stdin.readline
from collections import deque

t = int(input())

for _ in range(t):
    p = input().strip()
    n = int(input())

    if n > 0:
        x = input().strip()[1 : -1]
        xl = deque(map(int, x.split(',')))
    else:
        input()
        xl = deque([])

    left = True
    error = False

    i = 0
    while i < len(p):
        if i + 1 < len(p) and p[i:i+2] == 'RR':
            i += 1
        elif p[i] == 'R':
            left = not left
        elif not xl:
           error = True
           break
        elif left:
            xl.popleft()
        else:
            xl.pop()
        i += 1
    if error:
        print('error')
    elif left:
        print('[', ','.join(map(str, xl)), ']', sep='')
    else:
        l = len(xl)
        print('[', ','.join(str(xl[l - 1 - i]) for i in range(l)), ']', sep='')