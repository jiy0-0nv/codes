n = int(input())
xl = list(map(int, input().split()))

sl = sorted(xl)

rd = {}
r = -1
for i in range(n):
    if i == 0 or sl[i] != sl[i - 1]:
        r += 1
        rd[sl[i]] = r

print(' '.join(str(rd[x]) for x in xl))