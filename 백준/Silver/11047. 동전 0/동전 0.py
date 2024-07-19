import sys
input = sys.stdin.readline

n, k = map(int, input().split())
prev = int(input())
count = 0

for _ in range(n - 1):
    c = int(input())
    count += (k % c) // prev
    k -= k % c
    prev = c

if k != 0:
    count += k // prev
    
print(count)