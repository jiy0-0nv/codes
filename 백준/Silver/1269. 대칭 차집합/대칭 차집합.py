a, b = map(int, input().split())
al = set(map(int, input().split()))
bl = set(map(int, input().split()))
print(len((al - bl) | (bl - al)))