n = int(input())

def checkPrime(n):
    for i in range(2, int(n ** (1/2) + 1)):
        if n % i == 0:
            return False
    return True

def checkPalindrome(s):
    for i in range(len(s) // 2):
        if s[i] != s[len(s) - 1 - i]:
            return False
    return True

if n > 2 and n % 2 == 0:
    n += 1

while True:
    if n == 1:
        print(2)
        break
    if checkPrime(n) and checkPalindrome(str(n)):
        print(n)
        break
    n += 2