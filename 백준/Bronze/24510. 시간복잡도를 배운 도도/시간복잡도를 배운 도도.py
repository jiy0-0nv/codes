import sys
input = sys.stdin.readline

c = int(input())
ans = 0
for _ in range(c):
    code = input()
    ans = max(ans, code.count('for') + code.count('while'))
print(ans)