a, b, c = map(int, input().split())
a ^= b
if c % 2 == 0:
    a ^= b
print(a)