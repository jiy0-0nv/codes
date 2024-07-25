n = int(input())
fl = list(map(int, input().split()))
fl.sort()

if n == 2:
    print(f'{fl[0]} {fl[1]}')
elif fl[0] >= 0:
    print(f'{fl[0]} {fl[1]}')
elif fl[n - 1] <= 0:
    print(f'{fl[n - 2]} {fl[n - 1]}')
else:
    p1 = 0
    p2 = n - 1
    ans = [fl[p1], fl[p2]]
    absum = abs(fl[p1] + fl[p2])
    while p1 < p2 :
        sum = fl[p1] + fl[p2]
        if abs(sum) < absum:
            ans[0] = fl[p1]
            ans[1] = fl[p2]
            absum = abs(fl[p1] + fl[p2])
        if absum == 0:
            break
        elif sum > 0:
            p2 -= 1
        else:
            p1 += 1
    print(f'{ans[0]} {ans[1]}')