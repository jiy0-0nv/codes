import queue

n, k = map(int, input().split())

t = [-1] * 100001

q = queue.Queue()

q.put(n)
t[n] = 0

while not q.empty():
    p = q.get()
    if p == k:
        print(t[p])
        break
    lst = [p - 1, p + 1, p * 2]
    for i in lst:
        if 0 <= i < 100001 and t[i] < 0:
            q.put(i)
            t[i] = t[p] + 1