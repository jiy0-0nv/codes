import sys
input = sys.stdin.readline

g = 1

while True:
    n = int(input())
    if not n:
        exit(0)
    
    names = [None] * n
    arr = [[False] * n for _ in range(n)]
    for i in range(n):
        t = list(input().split())
        names[i] = t[0]
        for j in range(1, n):
            if t[n - j] == 'N':
                arr[i][(i + j) % n] = True
    
    print(f'Group {g}')
    non = True
    for i in range(n):
        for j in range(1, n):
            if arr[i][(i - j + n) % n]:
                non = False
                print(f'{names[(i - j + n) % n]} was nasty about {names[i]}')

    print('Nobody was nasty\n' if non else '')
    g += 1