import sys
input = sys.stdin.readline

pd = {}
pl = []
ps = set([])

for _ in range(int(input())):
    name, io = input().split()
    if io == 'enter':
        pd[name] = True
        if name not in ps:
            pl.append(name)
            ps.add(name)
    else:
        pd[name] = False

pl.sort(reverse=True)

for p in pl:
    if pd[p]:
        print(p)