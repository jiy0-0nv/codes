a, b, c = map(int,input().split())
ans = 1
if a % 2 == 0 and b % 2 == 0 and c % 2 == 0:
    ans = a * b * c
else:
    for i in [a, b, c]:
        if i % 2 == 1:
            ans *= i

print(ans)