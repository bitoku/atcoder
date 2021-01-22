def answer():
    n, m = map(int, input().split())
    ans = [-1] * n
    for i in range(m):
        s, c = map(int, input().split())
        if ans[s-1] != -1 and ans[s-1] != c:
            return -1
        ans[s-1] = c
    if n == 1 and (ans[0] == 0 or ans[0] == -1):
        return 0
    if ans[0] == 0:
        return -1
    if ans[0] == -1:
        result = 1
    else:
        result = ans[0]
    for i in range(1, n):
        if ans[i] == -1:
            result = result * 10
        else:
            result = result * 10 + ans[i]
    return result

print(answer())
