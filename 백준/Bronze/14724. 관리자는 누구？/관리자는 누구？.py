import sys
input = sys.stdin.readline

clubs = ['PROBRAIN', 'GROW', 'ARGOS', 'ADMIN', 'ANT', 'MOTION', 'SPG', 'COMON', 'ALMIGHTY']
m, ans = 0, None

input()
for i in range(9):
    kl = list(map(int, input().split()))
    if m < max(kl):
        m, ans = max(kl), clubs[i]

print(ans)