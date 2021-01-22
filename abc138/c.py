n = int(input())
v = list(map(int, input().split()))

v.sort()

before = v[0]
for i in v[1:]:
    before = (before + i) / 2

print(before)