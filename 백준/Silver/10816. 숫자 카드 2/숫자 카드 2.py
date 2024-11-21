input()
nl = list(map(int, input().split()))
input()
ml = list(map(int, input().split()))

ns = set()
nd = {}

for i in nl:
    if i in ns:
        nd[i] += 1
    else:
        ns.add(i)
        nd[i] = 1

for i in ml:
    print(nd[i] if i in ns else 0, end=" ")