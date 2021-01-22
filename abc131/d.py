N = int(input())

works_rev = []
for loop in range(N):
    a, b = list(map(int, input().split()))
    works_rev.append((b, a))

works_rev.sort()
t = 0
for b, a in works_rev:
    t += a
    if t > b:
        print("No")
        exit()
print("Yes")