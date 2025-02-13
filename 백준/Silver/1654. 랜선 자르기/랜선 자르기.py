import sys
input = sys.stdin.readline

k, n = map(int, input().split())
lst = [int(input()) for _ in range(k)]
end = sum(lst) // n
stt = 1
ans = (stt + end) // 2

while True:
    if stt == end:
        print(stt)
        break
    elif stt + 1 == end:
        ans = end

    count = 0
    for l in lst:
        count += (l // ans)

    if count >= n:
        stt = ans
    else:
        end = ans - 1
        
    ans = (stt + end) // 2