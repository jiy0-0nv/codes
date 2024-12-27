a, b, c = map(int, input().split())
a %= c

def mul(a, n):
    if n == 1:
        return a % c
    else:
        t = mul(a, n // 2)
        if n % 2:
            return (t * t * a) % c
        else:
            return (t * t) % c

print(mul(a, b))