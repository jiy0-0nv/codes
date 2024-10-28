s = input()
n = 1

for i in range(1, len(s)):
    if s[i - 1] != s[i]:
        n += 1

print(n // 2)