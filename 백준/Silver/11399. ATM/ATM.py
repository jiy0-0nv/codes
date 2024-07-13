n = int(input())
p = list(map(int, input().split()))

tmin = 0
p.sort()

for i in range(n):
    tmin += p[i] * (n - i)
    
print(tmin)