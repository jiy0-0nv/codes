from collections import deque
import sys
input = sys.stdin.readline

stack = deque([])
n = int(input())

for _ in range(n):
    c = input()
    if c[:2] == 'pu':
        stack.append(int(c[5:]))
    elif c[0] == 'p':
        print(stack.pop() if stack else -1)
    elif c[0] == 's':
        print(len(stack))
    elif c[0] == 'e':
        print(0 if stack else 1)
    else:
        print(stack[-1] if stack else -1)