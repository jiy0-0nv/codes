import sys
input = sys.stdin.readline

n, m = map(int, input().split())
cl = []
hl = []

for i in range(n):
    city = list(map(int, input().split()))
    for j in range(n):
        if city[j] == 1:
            hl.append((i, j))
        elif city[j] == 2:
            cl.append((i, j))

graph = [[0] * len(hl) for _ in range(len(cl))]
for i in range(len(cl)):
    for j in range(len(hl)):
        graph[i][j] = abs(cl[i][0] - hl[j][0]) + abs(cl[i][1] - hl[j][1])

rcl = []
ans = n * 2 * len(hl)

def back(b):
    if len(rcl) == m:
        al = [n * 2] * len(hl)
        for i in range(len(cl)):
            if i in rcl:
                for j in range(len(hl)):
                    al[j] = min(al[j], graph[i][j])

        global ans
        ans = min(ans, sum(al))
        return
    
    for i in range(b, len(cl)):
        rcl.append(i)
        back(i + 1)
        rcl.pop()

back(0)
print(ans)