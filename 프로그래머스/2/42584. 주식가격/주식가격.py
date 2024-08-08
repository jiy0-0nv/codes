def solution(prices):
    n = len(prices)
    answer = [i for i in range(n - 1, -1, -1)]
    
    stack = []
    for i in range(n):
        while stack and prices[stack[-1]] > prices[i]:
            j = stack.pop()
            answer[j] = i - j
        stack.append(i)
    return answer