import sys

def count(x, y, n):
    if n == 1:
        return f'{y[0]} {y[1]}'
    else:
        x[0] += y[0]
        x[1] += y[1]
        return count(y, x, n - 1)
    
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    if n == 0:
        print('1 0')
    else:
        print(count([1, 0], [0, 1], n))