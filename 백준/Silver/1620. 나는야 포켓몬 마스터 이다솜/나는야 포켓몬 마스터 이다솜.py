import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pd1 = {}
pd2 = {}

for i in range(1, n + 1):
    a = input().strip()
    pd1[a] = i
    pd2[i] = a

for _ in range(m):
    t = input().strip()
    try:
        print(pd2[int(t)])
    except:
        print(pd1[t])