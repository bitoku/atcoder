n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    if a[i]-1 == i:
        continue
    a[a[i]-1], a[i] = a[i], a[a[i]-1]
    break

if a == sorted(a):
    print("YES")
else:
    print("NO")