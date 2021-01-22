from collections import defaultdict

def answer():
    n, p = map(int, input().split())
    s = input()
    m = defaultdict(int)
    ans = 0
    if p == 2 or p == 5:
        for i, ss in enumerate(s):
            if int(ss) % p == 0:
                ans += i + 1
        return ans
    sss = 0
    for i, ss in enumerate(s[::-1]):
        sss = (sss + pow(10, i, p) * int(ss)) % p
        m[sss] += 1
    m[0] += 1
    for i in range(p):
        if m[i] >= 2:
            ans += m[i] * (m[i] - 1) // 2
    return ans

print(answer())


