n = int(input())
x = 1
while n % 2 == 0 and x < 10:
    x += 1
    n >>= 1
print(32 - x)