import queue

a, b, n, m = map(int, input().split())
brd = [-1] * 100001
q = queue.Queue()

q.put(n)
brd[n] = 0

def bfs():
    while not q.empty():
        p = q.get()

        if p == m:
            return brd[p]
        
        nlst = [p + 1, p - 1, p + a, p - a, p + b, p - b, p * a, p * b]

        for i in nlst:
            if 0 <= i < 100001 and brd[i] == -1:
                q.put(i)
                brd[i] = brd[p] + 1

print(bfs())