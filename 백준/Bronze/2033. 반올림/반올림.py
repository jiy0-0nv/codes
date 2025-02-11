n = int(input())

for i in range(1, len(str(n))):
    if n // (10 ** (i - 1)) % 10 < 5:
        n = n // (10 ** i) * 10 ** i
    else:
        n = n // (10 ** i) * 10 ** i + 10 ** i

print(n)