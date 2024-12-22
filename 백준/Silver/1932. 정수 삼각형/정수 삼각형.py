import sys
input = sys.stdin.readline

n = int(input())
urow = False
drow = [int(input())]

for i in range(2, n + 1):
    urow = drow[:]
    drow = list(map(int, input().split()))
    drow[0] += urow[0]
    for j in range(1, i - 1):
        drow[j] += max(urow[j - 1], urow[j])
    drow[i - 1] += urow[i - 2]

print(max(drow))