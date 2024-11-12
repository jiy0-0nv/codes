import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    elif n == 1:
        print("{ }")
    else:
        print("{ ", end="")
        n -= 1
        i = 1
        st = True
        while n > 0:
            if n & 1:
                if not st:
                    print(", ", end="")
                print(i, end="")
                st = False
            i *= 3
            n >>= 1
        print(" }")