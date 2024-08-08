import sys
input = sys.stdin.readline

tn = int(input())

for _ in range(tn):
    n, m = map(int, input().split())
    prt = list(map(int, input().split()))
    
    ans = 1
    while True:
        if prt[0] < max(prt):
            prt.append(prt.pop(0))
            if m == 0:
                m = len(prt) - 1
            else:
                m -= 1
        else:
            if m == 0:
                break
            prt.pop(0)
            m -= 1
            ans += 1
    print(ans)