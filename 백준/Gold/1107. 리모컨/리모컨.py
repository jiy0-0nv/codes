n = int(input())
m = int(input())
if m > 0:
    bts = set(map(int, input().split()))
else:
    bts = set()
ans = abs(n - 100)

def check(a):
    if a == 0 and 0 not in bts:
        return True
    while a:
        if a % 10 in bts:
            return False
        if a // 10 == 0:
            return True
        a //= 10

for i in range(ans):
    x, y = n - i, n + i

    if x >= 0 and check(x):
        ans = len(str(x)) + i
        break
    elif check(y):
        ans = len(str(y)) + i
        break

print(min(abs(n - 100), ans))