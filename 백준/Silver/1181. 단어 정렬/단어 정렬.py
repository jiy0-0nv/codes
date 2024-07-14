import sys

n = int(input())
wordlist = [None for _ in range(n)]

for i in range(n):
    w = sys.stdin.readline().strip()
    wordlist[i] = (len(w), w)

wordlist.sort()
for i in range(n):
    w = wordlist[i][1]
    if i == 0 or w != wordlist[i - 1][1]:
        print(w)