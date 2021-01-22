n = int(input())
ps = list(map(int, input().split()))

cnt = 0
for i in range(1, n-1):
    if ps[i - 1] > ps[i] >= ps[i + 1]:
        cnt += 1
    elif ps[i + 1] > ps[i] >= ps[i - 1]:
        cnt += 1

print(cnt)