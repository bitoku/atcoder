n = int(input())
a = list(map(int, input().split()))

summation = 0
for i in a:
    summation += 1 / i
print(1 / summation)