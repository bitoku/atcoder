n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cnt = 0
beaten = min(a[0], b[0])
b[0] -= beaten
cnt += beaten
for i in range(1, len(b)):
    beaten = min(a[i], b[i-1])
    a[i] -= beaten
    cnt += beaten
    beaten = min(a[i], b[i])
    b[i] -= beaten
    cnt += beaten
beaten = min(a[len(a)-1], b[len(b)-1])
cnt += beaten

print(cnt)