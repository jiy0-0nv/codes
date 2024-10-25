a, b = input().split()

ax = [-1 for _ in range(37)]
ad = {}
ast = set()
bx = [-1 for _ in range(37)]
bd = {}
bst = set()
ans = -1 #-1:Impossible, -2:Multiple

def c2n(c):
    c = ord(c)
    if c < 58:
        return c - 48
    elif c < 91:
        return c - 55
    else:
        return c - 87

s = c2n(max(max(a), max(b)))

for i in range(c2n(max(a)), 36):
    ax[i] = c2n(a[len(a) - 1])
    m = i
    for j in range(1, len(a)):
        ax[i] += c2n(a[len(a) - 1 - j]) * m
        m *= i

    if ax[i] in ast:
        ans = -2
        break

    ad[ax[i]] = i
    ast.add(ax[i])

for i in range(c2n(max(b)), 36):
    bx[i] = c2n(b[len(b) - 1])
    m = i
    for j in range(1, len(b)):
        bx[i] += c2n(b[len(b) - 1 - j]) * m
        m *= i

    if bx[i] in bst:
        ans = -2
        break

    bd[bx[i]] = i
    bst.add(bx[i])

    if bx[i] in ast and ad[bx[i]] != i:
        if ans == -1:
            ans = bx[i]
        else:
            ans = -2
            break

if ans == -1:
    print('Impossible')
elif ans == -2:
        print('Multiple')
else:
    print(ans, ad[ans], bd[ans])
