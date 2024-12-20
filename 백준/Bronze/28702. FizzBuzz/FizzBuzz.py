pl = [input() for _ in range(3)]
next = 0
for i in range(3):
    if pl[i][0] == 'F' or pl[i][0] == 'B':
        continue
    else:
        next = int(pl[i]) + (3 - i)
if next % 3 and next % 5:
    print(next)
elif next % 3:
    print("Buzz")
elif next % 5:
    print("Fizz")
else:
    print("FizzBuzz")