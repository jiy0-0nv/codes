import sys
input = sys.stdin.readline

n = int(input())
st = [0 for _ in range(n)]

for i in range(n):
    st[i] = int(input())

if n == 1:
    print(st[0])
elif n == 2:
    print(st[0] + st[1])
else:
    sc = [0 for _ in range(n)]
    sc[0] = st[0]
    sc[1] = st[1] + st[0]
    sc[2] = max(st[0], st[1]) + st[2]

    for i in range(3, n):
        sc[i] = st[i] + max(st[i - 1] + sc[i - 3], sc[i - 2])

    print(sc[n - 1])