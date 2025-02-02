import sys
input = sys.stdin.readline
from collections import deque

n, m = map(int, input().split())
board = [[True] * m for _ in range(n)]
coins = []

for i in range(n):
    line = input()
    for j in range(m):
        if line[j] == 'o':
            coins.append([i, j])
        elif line[j] == '#':
            board[i][j] = False

q = deque([[coins[0], coins[1], 0]])

while q:
    c1, c2, i = q.popleft()
    if i == 10: 
        print(-1)
        exit(0)

    t1, t2 = c1[:], c2[:]

    if c1[1] - 1 < 0:
        t1 = False
    elif board[c1[0]][c1[1] - 1]:
        t1[1] -= 1
    if c2[1] - 1 < 0:
        t2 = False
    elif board[c2[0]][c2[1] - 1]:
        t2[1] -= 1
    
    if (not t1) and (not t2): 
        pass
    elif (not t1) or (not t2):
        print(i + 1)
        exit(0)
    elif t1 and t2 and c1[1] == t1[1] and c2[1] == t2[1]:
        pass
    elif t1 and t2 and t1[0] == t2[0] and t1[1] == t2[1]:
        pass
    else:
        q.append([t1, t2, i + 1])

    t1, t2 = c1[:], c2[:]

    if t1[1] + 1 >= m:
        t1 = False
    elif board[t1[0]][t1[1] + 1]:
        t1[1] += 1
    if t2[1] + 1 >= m:
        t2 = False
    elif board[t2[0]][t2[1] + 1]:
        t2[1] += 1

    if (not t1) and (not t2):
        pass
    elif (not t1) or (not t2):
        print(i + 1)
        exit(0)
    elif t1 and t2 and c1[1] == t1[1] and c2[1] == t2[1]:
        pass
    elif t1 and t2 and t1[0] == t2[0] and t1[1] == t2[1]:
        pass
    else:
        q.append([t1, t2, i + 1])

    t1, t2 = c1[:], c2[:]

    if t1[0] - 1 < 0:
        t1 = False
    elif board[t1[0] - 1][t1[1]]:
        t1[0] -= 1
    if t2[0] - 1 < 0:
        t2 = False
    elif board[t2[0] - 1][t2[1]]:
        t2[0] -= 1

    if (not t1) and (not t2):
        pass
    elif (not t1) or (not t2):
        print(i + 1)
        exit(0)
    elif t1 and t2 and c1[0] == t1[0] and c2[0] == t2[0]:
        pass
    elif t1 and t2 and t1[0] == t2[0] and t1[1] == t2[1]:
        pass
    else:
        q.append([t1, t2, i + 1])
      
    t1, t2 = c1[:], c2[:]

    if t1[0] + 1 >= n:
        t1 = False
    elif board[t1[0] + 1][t1[1]]:
        t1[0] += 1
    if t2[0] + 1 >= n:
        t2 = False
    elif board[t2[0] + 1][t2[1]]:
        t2[0] += 1

    if (not t1) and (not t2):
        pass
    elif (not t1) or (not t2):
        print(i + 1)
        exit(0)
    elif t1 and t2 and c1[0] == t1[0] and c2[0] == t2[0]:
        pass
    elif t1 and t2 and t1[0] == t2[0] and t1[1] == t2[1]:
        pass
    else:
        q.append([t1, t2, i + 1])
    
print(-1)