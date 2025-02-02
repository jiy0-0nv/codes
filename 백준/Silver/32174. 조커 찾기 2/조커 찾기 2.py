import sys
input = sys.stdin.readline

n, m = map(int, input().split())
hl = [0] * (m + 1)

for h in range(m):
    s, i = map(int, input().split())
    if s == 1:
        hl[h + 1] = (hl[h] + i) % n
    elif s == 2:
        hl[h + 1] = (hl[h] - i) % n
    else:
        hl[h + 1] = hl[i]
print(hl[m] + 1)