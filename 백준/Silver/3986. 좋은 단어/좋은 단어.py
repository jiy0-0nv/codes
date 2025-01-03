n = int(input())
ans = 0

for _ in range(n):
    stack = []
    lst = list(input())
    for i in lst:
        if not stack:
            stack.append(i)
        elif stack[-1] == i:
            stack.pop(-1)
        else:
            stack.append(i)
    if not stack:
        ans += 1
        
print(ans)