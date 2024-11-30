import sys
input = sys.stdin.readline

n = int(input())
llst = list(map(int, input().split()))
q = int(input())

mlst = [0] * (n + 1)
for i in range(1, n):
    mlst[i] = mlst[i - 1]
    if llst[i] < llst[i - 1]:
        mlst[i] += 1

for _ in range(q):
    x, y = map(int, input().split())
    print(mlst[y - 1] - mlst[x - 1])