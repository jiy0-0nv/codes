def solution(s):
    answer = True
    l = 0
    
    for i in s:
        if i == '(':
            l += 1
        else:
            l -= 1
        if l < 0:
            return False
    if l != 0:
        answer = False

    return answer