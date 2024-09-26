n, m = map(int, input().split())
nl = list(map(int, input().split()))
nl.sort()
ans = []

def bt(t):
    if len(ans) == m:
        for i in ans:
            print(i, end=" ")
        print()
    else:
        for i in range(t, n):
            ans.append(nl[i])
            bt(i + 1)
            ans.pop()

bt(0)