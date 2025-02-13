n = int(input())
ans = 1
div = 10 ** 9 + 7

for i in range(n - 1, 0, -2):
    ans = (ans * i) % div

print(ans)