T = int(input())

for _ in range(T):
    lst = list(map(int, input().split()))
    avg = sum(lst[1:])/lst[0]
    cnt = 0
    for score in lst[1:]:
        if score > avg:
            cnt += 1
    rate = cnt/lst[0] * 100
    print(f"{rate:.3f}%")