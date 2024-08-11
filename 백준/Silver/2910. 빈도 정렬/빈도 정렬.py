n, c = map(int, input().split())
m = list(map(int, input().split()))
dct = {}
s = set()
lst = []

for i in m:
    if i in s:
        dct[i] += 1
    else:
        dct[i] = 1
        s.add(i)
        lst.append(i)

for i in range(len(lst)):
    lst[i] = (dct[lst[i]], i, lst[i])

lst.sort(key = lambda x:(-x[0], x[1]))

for i in lst:
    for _ in range(i[0]):
        print(i[2], end=" ")