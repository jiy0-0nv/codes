n = int(input())
d = 666
while n > 1:
    d += 1
    t = d
    while t >= 666:
        if t % 1000 == 666:
            n -= 1
            break
        else:
            t //= 10
print(d)
