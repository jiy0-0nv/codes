cl = [0] * 2

for j in range(2):
    xsum = 0
    ysum = 0
    for i in range(4):
        x, y = map(int, input().split())
        xsum += x
        ysum += y
    cl[j] = [xsum, ysum]

def gcd(a, b):
    if not a:
        return b
    x, y = max(a, b), min(a, b)
    r = x % y
    if not r:
        return y
    while y % r:
        t = r
        r = y % t
        y = t
    return r

p1, p2 = cl[0][1] - cl[1][1], cl[0][0] - cl[1][0]
s = 1 if (p1 > 0 and p2 > 0) or (p1 < 0 and p2 < 0) else -1
p1, p2 = abs(p1), abs(p2)
pd = gcd(p1, p2)
p1 = p1 // pd * s
p2 //= pd
print(f'{p1}/{p2}' if p2 > 1 else p1 // p2, end=" ")

q1, q2 = - p1 * cl[0][0] + p2 * cl[0][1], 4 * p2
s = 1 if (q1 > 0 and q2 > 0) or (q1 < 0 and q2 < 0) else -1
q1, q2 = abs(q1), abs(q2)
qd = gcd(q1, q2)
q1 = q1 // qd * s
q2 //= qd
print(f'{q1}/{q2}' if q2 > 1 else q1 // q2)