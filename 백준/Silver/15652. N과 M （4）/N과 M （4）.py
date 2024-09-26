n, m = map(int, input().split())
ans = []

def bt(t):
    if len(ans) == m:
        for i in ans:
            print(i, end=" ")
        print()
    else:
        for i in range(t, n + 1):
            ans.append(i)
            bt(i)
            ans.pop()

bt(1)