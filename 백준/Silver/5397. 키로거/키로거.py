import sys
input = sys.stdin.readline

n = int(input())

class pwd:
    def __init__(self, chr, prev, next):
        self.items = {'chr': chr, 'prev': prev, 'next': next}
    def __getitem__(self, i):
        return self.items[i]
    def __setitem__(self, i, value):
        self.items[i] = value

for _ in range(n):
    l = input().strip()
    head = None
    ptr = None
    for i in range(len(l)):
        if ord(l[i]) == 60:
            if ptr == None:
                continue
            elif ptr['prev'] == None:
                ptr = None
            else:
                ptr = ptr['prev']
        elif ord(l[i]) == 62:
            if head == None:
                continue
            elif ptr == None:
                ptr = head
            elif ptr['next'] == None:
                continue
            else:
                ptr = ptr['next']
        elif ord(l[i]) == 45:
            if ptr == None:
                continue
            elif ptr['next'] == None and ptr['prev'] == None:
                head = None
                ptr = None
            elif ptr['next'] == None:
                ptr = ptr['prev']
                ptr['next'] = None
            elif ptr['prev'] == None:
                head = ptr['next']
                head['prev'] = None
                ptr = None
            else:
                ptr['next']['prev'] = ptr['prev']
                ptr['prev']['next'] = ptr['next']
                ptr = ptr['prev']
        else:
            if head == None:
                newchr = pwd(l[i], None, None)
                head = newchr
                ptr = newchr
            elif ptr == None:
                newchr = pwd(l[i], None, head)
                head['prev'] = newchr
                head = newchr
                ptr = newchr
            elif ptr['next'] == None:
                newchr = pwd(l[i], ptr, None)
                ptr['next'] = newchr
                ptr = newchr
            else:
                newchr = pwd(l[i], ptr, ptr['next'])
                ptr['next']['prev'] = newchr
                ptr['next'] = newchr
                ptr = newchr
    while True:
        print(head['chr'], end='')
        if head['next'] == None:
            print('\n', end='')
            break
        head = head['next']