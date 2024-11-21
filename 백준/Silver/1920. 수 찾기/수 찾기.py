n = int(input())
al = set(map(int, input().split()))
m = int(input())
bl = list(map(int, input().split()))

for b in bl:
    if b in al:
        print(1)
    else:
        print(0)