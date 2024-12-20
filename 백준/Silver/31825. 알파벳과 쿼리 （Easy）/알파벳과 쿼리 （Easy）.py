import sys
input = sys.stdin.readline

n, q = map(int, input().split())
s = input().strip()

def count(x):
    res = 1
    for i in range(1, len(x)):
        if x[i - 1] != x[i]:
            res += 1
    return res

def change(x):
    res = ''
    for i in x:
        res += 'A' if i == 'Z' else chr(ord(i) + 1)
    return res

for _ in range(q):
    c, l, r = map(int, input().split())
    if c == 1:
        print(count(s[l - 1:r]))
    else:
        t = ''
        if l > 1:
            t += s[:l - 1]
        t += change(s[l - 1:r])
        if r < n:
            t += s[r:]
        s = t
