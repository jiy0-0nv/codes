import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nl = list(map(int, input().split()))

for i in range(1, n):
    nl[i] += nl[i - 1]

for _ in range(m):
    i, j = map(int, input().split())
    if i == 1:
        print(nl[j - 1])
    else:
        print(nl[j - 1] - nl[i - 2])