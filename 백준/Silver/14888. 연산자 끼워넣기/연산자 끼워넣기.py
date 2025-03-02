n = int(input())
al = list(map(int, input().split()))
ol = list(map(int, input().split()))
mx = -1000000000
mn = 1000000000

def bk(r, a, o):
    if o == 0:
        r += al[a]
    elif o == 1:
        r -= al[a]
    elif o == 2:
        r *= al[a]
    elif o == 3:
        if r < 0:
            r = (r // (-al[a])) * (-1)
        else:
            r //= al[a]
            
    a += 1
    if a == len(al):
        global mx, mn
        mx = max(mx, r)
        mn = min(mn, r)
        return

    for i in range(4):
        if ol[i]:
            ol[i] -= 1
            bk(r, a, i)
            ol[i] += 1

for i in range(4):
    if ol[i]:
        ol[i] -= 1
        bk(al[0], 1, i)
        ol[i] += 1

print(mx)
print(mn)