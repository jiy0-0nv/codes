import sys
input = sys.stdin.readline

n = int(input())
stack = []
idx = 1
ans = []

for _ in range(n):
    i = int(input())
    while idx <= i:
        ans.append('+')
        stack.append(idx)
        idx += 1
    if len(stack) > 0:
        ans.append('-')
        p = stack.pop()
    while p > i and len(stack) > 0:
        ans.append('-')
        p = stack.pop()
    if p != i:
        ans = []
        break

if len(ans) == 0:
    print('NO')
else:
    for i in ans:
        print(i)