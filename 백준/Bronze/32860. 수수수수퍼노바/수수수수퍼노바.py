n, m = map(int, input().split())
print("SN", n, end="")
if m < 27:
    print(chr(ord('A') + m - 1))
else:
    m -= 27
    print(chr(ord('a') + m // 26), end="")
    print(chr(ord('a') + m % 26), end="")