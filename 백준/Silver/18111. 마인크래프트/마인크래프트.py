import sys
input = sys.stdin.readline

n, m, b = map(int, input().split())
blocks = [0] * 257
sum = 0
ans1, ans2 = 256 * 500 * 500, -1

for _ in range(n):
    bs = map(int, input().split())
    for i in bs:
        blocks[i] += 1
        sum += i

for i in range(256, -1, -1):
    ans = 0
    if i * n * m > sum + b:
        continue
    for j in range(257):
        if j > i:
            ans += (j - i) * 2 * blocks[j]
        elif j < i:
            ans += (i - j) * blocks[j]
    if ans < ans1:
        ans1 = ans
        ans2 = i
        
print(ans1, ans2)