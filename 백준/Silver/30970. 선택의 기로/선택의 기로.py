import sys
input = sys.stdin.readline

n = int(input())
costs = [0] * n

for i in range(n):
    costs[i] = tuple(map(int, input().split()))

costs.sort(key=lambda x : (-x[0], x[1]))
print(costs[0][0], costs[0][1], costs[1][0], costs[1][1])

costs.sort(key=lambda x : (x[1], -x[0]))
print(costs[0][0], costs[0][1], costs[1][0], costs[1][1])
