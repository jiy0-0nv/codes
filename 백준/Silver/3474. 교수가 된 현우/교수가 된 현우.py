import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    tm = 2
    fm = 5
    tn = 0
    fn = 0
    while tm <= n:
        if n // tm > 0:
            tn += n // tm
            tm *= 2
        else:
            break
    while fm <= n:
        if n // fm > 0:
            fn += n // fm
            fm *= 5
        else:
            break
    print(min(tn, fn))