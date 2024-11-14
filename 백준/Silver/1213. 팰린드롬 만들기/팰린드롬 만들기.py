name = [c for c in input()]
name.sort()
ans = ''
m = ''
i = 0
while True:
    if i == len(name):
        break
    if i + 1 < len(name) and name[i] == name[i + 1]:
        ans += name[i]
        i += 2
    elif m == '':
        m = name[i]
        i += 1
    else:
        ans = ''
        m = "I'm Sorry Hansoo"
        break
print(ans + m + ans[::-1])