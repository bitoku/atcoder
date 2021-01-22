from collections import deque

def answer():
    s = deque(input())
    q = int(input())
    rev = False
    for i in range(q):
        query = input().split()
        if int(query[0]) == 2:
            f, c = int(query[1]), query[2]
            if (not rev and f == 1) or (rev and f == 2):
                s.appendleft(c)
            else:
                s.append(c)
        else:
            rev = not rev
    if rev:
        s = list(s)
        s = s[::-1]
    print(''.join(s))
    return

answer()