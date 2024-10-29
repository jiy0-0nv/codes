import sys
input = sys.stdin.readline

k = int(input())
dl = [0 for _ in range(6)]
ll = [0 for _ in range(6)]
ip = 0

for i in range(6):
    dl[i], ll[i] = map(int, input().split())
    if i == 0 or (dl[i - 1] == 1 and dl[i] == 4) or (dl[i - 1] == 4 and dl[i] == 2) or (dl[i - 1] == 2 and dl[i] == 3) or (dl[i - 1] == 3 and dl[i] == 1):
        continue
    else:
        ip = i

ans = (ll[(ip + 2) % 6] * ll[(ip + 3) % 6]) - (ll[ip] * ll[(ip + 5) % 6])
print(ans * k)