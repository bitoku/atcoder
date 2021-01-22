n, k = list(map(int, input().split()))
mod = int(1e9 + 7)

a, b = 2000, 2000
dp = [[0 for i in range(b+1)] for j in range(a+1)]
for j in range(b+1):
    dp[0][j] = 0
for i in range(a + 1):
    dp[i][0] = 1

for i in range(1, a+1):
    for j in range(1, b+1):
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod


for i in range(1, k+1):
    print(dp[n-k+1][i] * dp[k-1][i-1] % mod)
