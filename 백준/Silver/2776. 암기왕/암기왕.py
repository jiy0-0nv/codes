import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    input()
    note = set(map(int, input().split()))
    input()
    for n in map(int, input().split()):
        if n in note:
            print('1')
        else:
            print('0')