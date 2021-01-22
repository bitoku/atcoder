N, L = list(map(int, input().split()))

s = sum(range(L, L+N))
LL = L + N - 1
if L >= 0:
    print(s - L)
elif L < 0 and LL >= 0:
    print(s)
elif L < 0 and LL < 0:
    print(s - LL)
