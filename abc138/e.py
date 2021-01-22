from bisect import bisect
s = input()
t = input()

alphabet = 'abcdefghijklmnopqrstuvwxyz'
char = {c: [] for c in alphabet}
for i, c in enumerate(s):
    char[c].append(i)

if len(char[t[0]]) == 0:
    print(-1)
    exit()

result = char[t[0]][0]

for c in t[1:]:
    if len(char[c]) == 0:
        print(-1)
        exit()
    idx = bisect(char[c], result % len(s))
    result = result - result % len(s)
    try:
        result += char[c][idx]
    except IndexError:
        result += len(s) + char[c][0]

print(result+1)
