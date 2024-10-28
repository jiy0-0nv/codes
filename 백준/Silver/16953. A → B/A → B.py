a, b = map(int, input().split())
ans = 1

while b > a:
    if b % 2 == 0:
        if b // 2 < a:
            ans = -1
            break
        else:
            b //= 2
            ans += 1
    elif b % 10 == 1:
        if b // 10 < a:
            ans = -1
            break
        else:
            b //= 10
            ans += 1
    else:
        ans = -1
        break

print(ans)