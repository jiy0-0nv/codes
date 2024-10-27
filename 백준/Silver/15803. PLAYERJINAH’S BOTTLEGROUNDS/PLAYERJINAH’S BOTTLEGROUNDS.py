x = [0, 0, 0]
y = [0, 0, 0]

for i in range(3):
    x[i], y[i] = map(int, input().split())

if (x[0] == x[1] and x[1] == x[2]) or (x[0] != x[1] and x[1] != x[2] and (y[0] - y[1]) / (x[0] - x[1]) == (y[1] - y[2]) / (x[1] - x[2])):
    print("WHERE IS MY CHICKEN?")
else:
    print("WINNER WINNER CHICKEN DINNER!")