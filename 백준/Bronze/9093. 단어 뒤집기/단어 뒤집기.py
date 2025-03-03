import sys
input = sys.stdin.readline

for _ in range(int(input())):
    wl = list(input().split())
    for w in wl:
        print(w[::-1], end=' ')
    print()