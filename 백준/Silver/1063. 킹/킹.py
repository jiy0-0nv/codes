import sys
input = sys.stdin.readline

k, s, n = input().split()

kp = [ord(k[0]), int(k[1])]
sp = [ord(s[0]), int(s[1])]
move = {'R':(1, 0), 'L':(-1, 0), 'B':(0, -1), 'T':(0, 1),
        'RT':(1, 1), 'LT':(-1, 1), 'RB':(1, -1), 'LB':(-1, -1)}

for _ in range(int(n)):
    d = input().strip()
    if ord('A') <= kp[0] + move[d][0] <= ord('H') and 1 <= kp[1] + move[d][1] <= 8 :
        if kp[0] + move[d][0] == sp[0] and kp[1] + move[d][1] == sp[1]:
            if ord('A') <= sp[0] + move[d][0] <= ord('H') and 1 <= sp[1] + move[d][1] <= 8 :
                kp[0] += move[d][0]
                kp[1] += move[d][1]
                sp[0] += move[d][0]
                sp[1] += move[d][1]
        else:
            kp[0] += move[d][0]
            kp[1] += move[d][1]

print(f'{chr(kp[0])}{kp[1]}\n{chr(sp[0])}{sp[1]}')