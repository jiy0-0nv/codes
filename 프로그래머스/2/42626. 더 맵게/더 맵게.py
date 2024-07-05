from queue import PriorityQueue

def solution(scoville, K):
    answer = 0
    queue = PriorityQueue()
    
    for i in scoville:
        queue.put(i)
    
    while True:
        a = queue.get()
        if a >= K:
            break
        if queue.qsize() == 0:
            return -1
        b = queue.get()
        queue.put(a + b * 2)
        answer += 1
    
    return answer