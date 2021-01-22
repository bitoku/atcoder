f1 = input().split()
f2 = input().split()
f3 = input().split()
f = [f1, f2, f3]

n = int(input())
for i in range(n):
    b = input()
    if b in f1:
        a = f1.index(b)
        f1[a] = 0
    elif b in f2:
        a = f2.index(b)
        f2[a] = 0
    elif b in f3:
        a = f3.index(b)
        f3[a] = 0

def judge():
    bingoc = True
    bingod = True
    for i in range(3):
        bingoa = True
        bingob = True
        for j in range(3):
            if f[i][j] != 0:
                bingoa = False
            if f[j][i] != 0:
                bingob = False
        if bingoa or bingob:
            print('Yes')
            return

        if f[i][i] != 0:
            bingoc = False
        if f[i][2-i] != 0:
            bingod = False
    if bingoc or bingod:
        print('Yes')
        return
    print('No')

judge()


