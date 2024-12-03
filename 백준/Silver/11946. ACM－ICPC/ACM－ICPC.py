import sys
input = sys.stdin.readline

n, m, q = map(int, input().split())
tl = [[0 for _ in range(m + 1)] for _ in range(n + 1)] # 틀린 횟수
td = {i: {'solved': 0, 'score': 0} for i in range(1, n + 1)}

for _ in range(q):
    s, t, p, r = input().split()
    s, t, p = map(int, [s, t, p])
    if tl[t][p] < 0:
        continue
    if r == 'AC':
        td[t]['solved'] += 1
        td[t]['score'] += s + tl[t][p] * 20
        tl[t][p] = -1
    else:
        tl[t][p] += 1

rl = [(i, td[i]['solved'], td[i]['score']) for i in range(1, n + 1)]
rl.sort(key=lambda x:(-x[1], x[2], x[0]))

for i in rl:
    print(i[0], i[1], i[2])