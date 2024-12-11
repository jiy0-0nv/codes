s = input()
l = len(s)
ans = 1
i = 0
c = s[i]
a = str(ans)

while True:
    for j in range(len(a)):
        if c == a[j]:
            i += 1
            if i == l:
                print(ans)
                exit(0)
            c = s[i]
        elif c not in a[j:]:
            break
    ans += 1
    a = str(ans)
