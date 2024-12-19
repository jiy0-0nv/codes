n = int(input())
ml = list(map(int, input().split()))
al = []

for i in range(n - 1, -1, -1):
    al.insert(ml[i], i + 1)

print(' '.join(str(i) for i in al))