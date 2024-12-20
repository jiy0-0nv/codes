import sys
input = sys.stdin.readline

while True:
    s = input()
    if s[0] == '.':
        break
    stack = []
    for c in s:
        if c == '.':
            if stack:
                print('no')
            else:
                print('yes')
            break
        if c == '[' or c =='(':
            stack.append(c)
        elif (c == ']' and (not stack or stack.pop() == '(')) or (c == ')' and (not stack or stack.pop() == '[')):
                print('no')
                break
