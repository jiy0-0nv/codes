import sys
input = sys.stdin.readline

n, m = map(int, input().split())
passwords = {}

for _ in range(n):
    s, p = input().split()
    passwords[s] = p

for _ in range(m):
    print(passwords[input().strip()])