n, r, c = map(int, input().split())

def quad(a, b, n, ans):
    if n < 0:
        return ans
    
    x, y = False, False
    if a >= 2 ** n:
        a -= 2 ** n
        x = True
    if b >= 2 ** n:
        b -= 2 ** n
        y = True

    if x and y:
        i = 3
    elif x:
        i = 2
    elif y:
        i = 1
    else:
        i = 0
    ans = quad(a, b, n - 1, ans + i * ((2 ** n) ** 2))
    return ans

print(quad(r, c, n - 1, 0))