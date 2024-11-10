a = int(input(), 2)
b = int(input(), 2)
n = 100000
m = 2 ** n - 1

print(bin(a & b)[2:].zfill(n), bin(a | b)[2:].zfill(n), bin(a ^ b)[2:].zfill(n), bin(a ^ m)[2:].zfill(n), bin(b ^ m)[2:].zfill(n), sep='\n')
