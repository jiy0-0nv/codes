n, m = map(int, input().split())
nl = list(map(int, input().split()))
nl.sort()

ans = []

def back(s):
    if len(ans) == m:
        print(' '.join(map(str, ans)))
        return
    for i in range(s, n):
        if i > 0 and nl[i - 1] == nl[i]:
            continue
        ans.append(nl[i])
        back(i)
        ans.pop()

back(0)