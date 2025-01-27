n = int(input())
al = list(map(int, input().split()))
al.sort()
print(sum(al[:n // 2]), sum(al[n // 2:]))