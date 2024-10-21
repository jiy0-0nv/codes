n = int(input())

def opr(x):
    y = x // 10 + x % 10 if x >= 10 else x
    y = (x % 10) * 10 + y % 10
    return y

nn = opr(n)
c = 1

while nn != n:
    nn = opr(nn)
    c += 1

print(c)