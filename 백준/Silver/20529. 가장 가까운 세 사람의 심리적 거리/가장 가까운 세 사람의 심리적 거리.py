import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    mbti = list(input().split())
    if n > 32:
        print(0)
    else:
        ans = 9
        for i in range(0, n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    u = 0
                    for a in range(4):
                        if mbti[i][a] != mbti[j][a]:
                            u += 1
                        if mbti[i][a] != mbti[k][a]:
                            u += 1
                        if mbti[j][a] != mbti[k][a]:
                            u += 1
                    ans = min(ans, u)
        print(ans)