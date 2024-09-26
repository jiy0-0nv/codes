n, m = map(int, input().split())
nl = list(map(int, input().split()))
nl.sort()
ans = []

def bt():
    if len(ans) == m:
        for i in ans:
            print(i, end=" ")
        print()
    else:
        for i in range(n):
            if nl[i] in ans:
                continue
            ans.append(nl[i])
            bt()
            ans.pop()

bt()