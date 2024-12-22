nl = [True] * 10001

for i in range(10000):
    d = i
    for j in str(i):
        d += int(j)
    if d < 10001:
        nl[d] = False

for i in range(1, 10001):
    if nl[i]:
        print(i)