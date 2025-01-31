import sys
input = sys.stdin.readline

r, c = map(int, input().split())
r -= 1
c -= 1
bomb = [set(), set()]

for i in range(10):
    line = input()
    for j in range(10):
        if line[j] == 'o':
            bomb[0].add(i)
            bomb[1].add(j)

ans = 20
for i in range(10):
    if i in bomb[0]:
        continue
    for j in range(10):
        if j not in bomb[1]:
            ans = min(ans, abs(i - r) + abs(j - c))

print(ans)