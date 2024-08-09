s = input()
i, j = 0, 0
st = set()
while not (i == j and j == len(s)):
    if s[i:j] not in st:
        st.add(s[i:j])
    if j == len(s):
        i += 1
        j = i
    else:
        j += 1
print(len(st) - 1)