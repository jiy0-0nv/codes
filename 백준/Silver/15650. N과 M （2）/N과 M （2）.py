n, m = map(int, input().split())
ans = []

def bt():
    if len(ans) == m:
        for i in ans:
            print(i, end=" ")
        print()
    else:
        for i in range(1, n + 1):
            if not len(ans) == 0 and i <= ans[len(ans) - 1]:
                continue
            ans.append(i)
            bt()
            ans.pop()

bt()