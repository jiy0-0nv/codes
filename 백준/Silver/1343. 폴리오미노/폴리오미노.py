board = input()
b1 = [b for b in board.split(sep='.') if b]
b2 = [b for b in board.split(sep='X') if b]

if board[0] == '.':
    ans = b2[0]
    b2 = b2[1:]
else:
    ans = ''

for i in range(len(b1)):

    l = len(b1[i])
    if l % 2:
        ans = -1
        break
    elif l % 4:
        ans += 'A' * (l - 2) + 'BB'
    else:
        ans += 'A' * l

    if i < len(b2):
        ans += b2[i]
print(ans)