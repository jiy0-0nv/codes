def solution(citations):
    hindex = 0
    citations.sort()
    i = 0
    
    if len(citations) < citations[0]:
        return len(citations)
    
    for i in range(len(citations)):
        if i + 1 >= citations[len(citations) - 1 - i]:
            hindex = citations[len(citations) - 1 - i]
            break
    
    if i == 0:
        return 0
    
    for h in range(citations[len(citations) - 1 - i], citations[len(citations) - i]):
        if i >= h:
            hindex = h
    return hindex