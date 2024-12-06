wl = [input(), input(), input(), input(), input()]

ll = [len(i) for i in wl]

ans = ""

for i in range(max(ll)):
    for j in range(5):
        if ll[j] > i:
            ans += wl[j][i]

print(ans)
