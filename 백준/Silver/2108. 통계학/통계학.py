import sys
input = sys.stdin.readline

n = int(input())
nl = [0] * n
ncl = [0] * 8001
nsm = 0
ma, c = [4001, 4001], -1

for i in range(n):
    t = int(input())
    nl[i] = t
    nsm += t
    ncl[t + 4000] += 1
    if ncl[t + 4000] > c:
        ma[0] = t
        ma[1] = 4001
        c = ncl[t + 4000]
    elif ncl[t + 4000] == c:
        if ma[0] > t:
            ma[1] = ma[0]
            ma[0] = t
        elif ma[0] <= t < ma[1]:
            ma[1] = t

nl.sort()
print(round(nsm / n))
print(nl[n // 2])
print(ma[0] if ma[1] == 4001 else ma[1])
print(nl[n - 1]-nl[0])