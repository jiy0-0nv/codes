x = int(input())
y = int(input())

coms = {}
for i in range(x):
    coms[i + 1] = [0, []]
for _ in range(y):
    [a, b] = map(int, input().split())
    coms[a][1].append(b)
    coms[b][1].append(a)
    
global sum
sum = 0

def search(n):
    global sum
    if coms[n][0] == 1:
        return sum
    else:
        coms[n][0] = 1
        sum += 1
        for i in coms[n][1]:
            search(i)
        return sum
    
print(search(1) - 1)