MOD = int(1e9 + 7)

s = input()
digits = len(s)

cnt = 0
for i, c in enumerate(reversed(s)):
    if c == '?':
        continue
    n = int(c) * pow(10, i, 13) % 13
    cnt += n
# print(cnt)

before = [0] * 13
first_time = True
for i, c in enumerate(reversed(s)):
    if c != '?':
        continue
    if first_time:
        for j in range(10):
            n = j * pow(10, i, 13) % 13
            before[n] += 1
        first_time = False
        continue
    current = [0] * 13
    for j in range(10):
        n = j * pow(10, i, 13) % 13
        current[n] += 1
    after = [0] * 13
    for j in range(13):
        for k in range(13):
            after[j] += before[k] * current[(13 - k + j) % 13]
        after[j] %= MOD
    before = after

if first_time:
    if cnt % 13 == 5:
        print(1)
    else:
        print(0)
else:
    print(before[(5 - (cnt % 13)) % 13])
