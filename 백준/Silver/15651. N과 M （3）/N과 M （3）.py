n, m = map(int, input().split())
ans = []

def bt():
    if len(ans) == m:
        for i in ans:
            print(i, end=" ")
        print()
    else:
        for i in range(1, n + 1):
            ans.append(i)
            bt()
            ans.pop()

bt()