x, n = map(int, input().split())

if (n == 1 and x < 0) or (n == 0 and x > 0):
    print("INFINITE")
elif n <= 1:
    print(0)
elif n % 2:
    print("ERROR")
elif x - n // 2 <= 0:
    print(0)
elif x % (n // 2):
    print(x // (n // 2))
else:
    print(x // (n // 2) - 1)