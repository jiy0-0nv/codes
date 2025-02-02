import sys
input = sys.stdin.readline

jk = 1
n = int(input())

for _ in range(n):
    al = list(map(int, input().split()))
    njk = 0
    if jk > 13:
        jk -= 13
        for i in range(len(al)):
            if i % 2:
                njk += al[i]
            elif jk <= al[i]:
                njk += jk
                break
            else:
                njk += al[i]
                jk -= al[i]
    else:
        for i in range(len(al)):
            if not i % 2:
                njk += al[i]
            elif jk <= al[i]:
                njk += jk
                break
            else:
                njk += al[i]
                jk -= al[i]
    jk = njk
print(jk)