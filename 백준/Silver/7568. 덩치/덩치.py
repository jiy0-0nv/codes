import sys
input = sys.stdin.readline

n = int(input())
pl = [0 for _ in range(n)]
for i in range(n):
    pl[i] = tuple(map(int, input().split()))

rl = [1 for _ in range(n)]
for i in range(n):
    for j in range(i + 1, n):
        if pl[i][0] > pl[j][0] and pl[i][1] > pl[j][1]:
            rl[j] += 1
        elif pl[i][0] < pl[j][0] and pl[i][1] < pl[j][1]:
            rl[i] += 1

print(' '.join(str(i) for i in rl))