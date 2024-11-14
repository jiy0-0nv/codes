import sys
input = sys.stdin.readline

n, m = map(int, input().split())

trains = [0] * n

for _ in range(m):
    s = list(map(int, input().split()))
    c = s[0]
    t = s[1] - 1

    if c == 1:
        x = s[2] - 1
        trains[t] |= 1 << x
    elif c == 2:
        x = s[2] - 1
        trains[t] &= ~(1 << x)
    elif c == 3:
        trains[t] = (trains[t] << 1) & ((1 << 20) - 1)
    elif c == 4:
        trains[t] >>= 1

ts = set(trains)
print(len(ts))