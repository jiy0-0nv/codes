y = list(map(int, input().split()))
p = [0, 0, 0]

for i in range(3):
    p[i] = list(map(int, input().split()))

def d2(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** (1/2)

c = [[0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]]
ans = 90

for i in c:
    d = d2(y, p[i[0]]) + d2(p[i[0]], p[i[1]]) + d2(p[i[1]], p[i[2]])
    ans = min(ans, d)

print(int(ans))