n, m = map(int, input().split())
nl = list(map(int, input().split()))
nl.sort()
ans = []

def bt(pp):
    if len(ans) == m:
        print(' '.join(str(nl[s]) for s in ans))
    else:
        for i in range(n):
            if (pp == -1 or nl[i] != nl[pp]) and i not in ans:
                ans.append(i)
                bt(-1)
                pp = ans.pop()
bt(-1)