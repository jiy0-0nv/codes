n, s = map(int, input().split())
nlst = list(map(int, input().split()))

if max(nlst) >= s:
    print(1)
else:
    slst = [0] * n
    slst[0] = nlst[0]
    rlst = [-1] * n
    ans = n + 1

    for i in range(1, n):
        slst[i] = slst[i - 1] + nlst[i]
        if slst[i] >= s:
            for j in range(max(0, rlst[i - 1]), i):
                if slst[i] - slst[j] < s or j == i - 1:
                    rlst[i] = j
                    break
            ans = min(ans, i - rlst[i] + 1)
    print(0 if ans == n + 1 else ans)