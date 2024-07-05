def solution(scoville, K):
    answer = 0
    idx = 0
    mix = []
    midx = 0
    
    scoville.sort()
    if scoville[0] >= K:
        return 0
    else:
        mix.append(scoville[idx] + scoville[idx + 1] * 2)
        answer = 1
        idx = 2

    while (len(mix) > midx and mix[midx] < K) or (len(scoville) > idx and scoville[idx] < K):
        if len(scoville) - idx < 0 or (len(scoville) - idx == 0 and len(mix) - midx < 2) or (len(scoville) - idx == 1 and len(mix) - midx == 0):
            return -1
        if len(scoville) - idx > 1 and (len(mix) - midx < 1 or scoville[idx + 1] <= mix[midx]):
            mix.append(scoville[idx] + scoville[idx + 1] * 2)
            idx += 2
            answer += 1
        elif len(scoville) - idx > 0 and (len(mix) - midx < 2 or scoville[idx] <= mix[midx + 1]):
            if (scoville[idx] < mix[midx]):
                mix.append(scoville[idx] + mix[midx] * 2)
            else:
                mix.append(scoville[idx] * 2 + mix[midx])
            idx += 1
            midx += 1
            answer += 1
        else:
            mix.append(mix[midx] + mix[midx + 1] * 2)
            midx += 2
            answer += 1
    
    return answer