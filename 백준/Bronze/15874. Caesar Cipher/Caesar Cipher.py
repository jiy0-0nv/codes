k, l = map(int, input().split())
s = input()

for c in s:
    i = ord(c)
    if 65 <= i <= 90:
        print(chr((i - 65 + k) % 26 + 65), end='')
    elif 97 <= i <= 122:
        print(chr((i - 97 + k) % 26 + 97), end='')
    else:
        print(c, end='')