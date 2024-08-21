def solution(skill, skill_trees):
    answer = 0
    skdic = {}
    for i in range(len(skill)):
        skdic[skill[i]] = i
    # check skill tree
    for st in skill_trees:
        answer += 1
        order = -1
        for s in st:
            if s in skill:
                if skdic[s] == order + 1:
                    order += 1
                else:
                    answer -= 1
                    break
    return answer