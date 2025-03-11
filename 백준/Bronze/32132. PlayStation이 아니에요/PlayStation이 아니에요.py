n = int(input())
s = input()
ps = 0

for c in s:
    if c == 'P':
        ps = 1
    elif c == 'S' and ps == 1:
        ps = 2
    elif ps == 2 and (c == '4' or c == '5'):
        continue
    else:
        ps = 0
    print(c, end='')