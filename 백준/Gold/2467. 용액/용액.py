N = int(input())
values = list(map(int, input().split()))
values.sort()

LEFT = 0
RIGHT = N-1

left_value = values[0]
right_value = values[N-1]

while (LEFT<RIGHT):
    sum = values[LEFT]+values[RIGHT]
    if (sum == 0):
        break
    elif (sum > 0):
        RIGHT-=1
    else:
        LEFT+=1
    if (LEFT==RIGHT):
        break
    if (abs(values[LEFT]+values[RIGHT])<abs(left_value+right_value)):
        left_value, right_value = values[LEFT], values[RIGHT]

print(left_value, right_value)