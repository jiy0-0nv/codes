a = input()
b = input()

andl = [0] * len(a)
orl = [0] * len(a)
xorl = [0] * len(a)
na = [0] * len(a)
nb = [0] * len(a)

for i in range(len(a)):
    if a[i] == '1':
        if b[i] == '0':
            orl[i] = 1
            xorl[i] = 1
            nb[i] = 1
        else:
            andl[i] = 1
            orl[i] = 1
    else:
        if b[i] == '0':
            na[i] = 1
            nb[i] = 1
        else:
            orl[i] = 1
            xorl[i] = 1
            na[i] = 1

print(''.join(str(s) for s in andl))
print(''.join(str(s) for s in orl))
print(''.join(str(s) for s in xorl))
print(''.join(str(s) for s in na))
print(''.join(str(s) for s in nb))