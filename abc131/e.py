from itertools import combinations
N, K = list(map(int, input().split()))

def combination_2(n):
    return n * (n-1) // 2


if N == 2 and K > 0:
    print("-1")
    exit()

if N == 2 and K == 0:
    print(1)
    print(1, 2)
    exit()

max_K = combination_2(N-1)

if K > max_K:
    print("-1")
    exit()

M = max_K - K + N - 1
print(M)
cnt = 0
for x, y in combinations(range(1, N+1), 2):
    print(x, y)
    cnt += 1
    if cnt >= M:
        exit()
