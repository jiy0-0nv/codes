import sys
input = sys.stdin.readline

k = int(input())
nodelist = list(map(int, input().split()))

for l in range(k):
    for i in range(2 ** l):
        print(nodelist[(2 ** (k - l - 1) - 1) + (2 ** (k - l)) * i], end=" ")
    print()