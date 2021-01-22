n = int(input())
ds = list(map(int, input().split()))

ds.sort()

half = n // 2 - 1
k_min = ds[half]
k_max = ds[half+1]

print(k_max-k_min)