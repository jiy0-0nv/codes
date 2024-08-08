s = input()
sticks = 0
pieces = 0
for i in range(len(s)):
    if s[i] == '(' and s[i + 1] == ')':
        pieces += sticks
        i += 1
    elif s[i] == '(':
        sticks += 1
    elif s[i] == ')' and s[i - 1] != '(':
        sticks -= 1
        pieces += 1
print(pieces)