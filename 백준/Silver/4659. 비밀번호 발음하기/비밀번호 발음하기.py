import sys
input = sys.stdin.readline

VOWELS = set('aeiou')

while True:
    t = input().strip()

    if t == 'end':
        exit(0)

    c1, c2, c3 = False, True, True
    vow, con, prev = 0, 0, ''

    for c in t:
        if c in VOWELS:
            if not c1:
                c1 = True
            if c == prev and c != 'e' and c != 'o':
                c3 = False
                break
            vow, con, prev = vow + 1, 0, c
            if vow == 3:
                c2 = False
                break
        else:
            if c == prev:
                c3 = False
                break
            vow, con, prev = 0, con + 1, c
            if con == 3:
                c2 = False
                break
    
    acc = ' ' if c1 and c2 and c3 else ' not '
    print(f'<{t}> is{acc}acceptable.')