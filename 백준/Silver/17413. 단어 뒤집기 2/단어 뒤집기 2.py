s = input()
x = 0
tag = False

for i in range(len(s)):
    c = s[i]
    if c == "<":
        print(''.join(s[i - 1 - t] for t in range(i - x)), end='')
        tag = True
        x = i
    elif c == ">":
        print(s[x:i+1], end='')
        tag = False
        x = i + 1
    elif tag:
        continue
    elif c == " ":
        print(''.join(s[i - 1 - t] for t in range(i - x)), end=' ')
        x = i + 1
    else:
        continue

l = len(s)
if x < len(s):
        print(''.join(s[l - 1 - t] for t in range(l - x)), end='')