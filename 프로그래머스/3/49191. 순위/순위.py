def solution(n, results):
    rst = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    
    for r in results:
        rst[r[0]][r[1]] = 1 # win
        rst[r[1]][r[0]] = -1 # lose
                
    for i in range(n + 1):
        for j in range(n + 1):
            if rst[i][j] == 1: # i > j
                for k in range(n + 1):
                    if rst[k][i] == 1 and rst[k][j] == 0: # k > i
                        rst[k][j] = 1 # k > j
                        rst[j][k] = -1
                    if rst[j][k] == 1 and rst[i][k] == 0: # j > k
                        rst[i][k] = 1 # i > k
                        rst[k][i] = -1
    answer = 0    
    for rec in rst:
        if rec.count(0) == 2:
            answer += 1
    
    return answer