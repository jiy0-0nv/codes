n = int(input())
codes = list(map(int, input().split()))
s = input()
ans = [-1] * n

codes.sort()
for i in range(n):
    c = s[i]
    if c == ' ':
        ans[i] = 0
    elif 'A' <= c <= 'Z':
        ans[i] = ord(c) - ord('A') + 1
    else:
        ans[i] = ord(c) - ord('a') + 27
ans.sort()

for i in range(n):
    if codes[i] != ans[i]:
        print('n')
        exit(0)
print('y')