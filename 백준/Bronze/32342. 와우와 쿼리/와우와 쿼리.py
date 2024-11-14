import sys
input = sys.stdin.readline

q = int(input())
for _ in range(q):
    s = input().strip()
    ans = 0
    for i in range(len(s) - 2):
        if s[i:i + 3] == 'WOW':
            ans += 1
    print(ans)