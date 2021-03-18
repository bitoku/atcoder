#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll dp[8][101];

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

ll memo[10];

ll pattern(int x) {
    if (x <= 0) return 1;
    if (memo[x]) return memo[x];
    memo[x] = pattern(x - 1) + pattern(x - 2);
    return memo[x];
}

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    k--;
    dp[0][0] = 1;
    for (int i = 1; i <= h; ++i) {
        dp[0][i] = dp[0][i-1] * pattern(w - 2) % mod;
        if (w > 1) {
            dp[0][i] += dp[1][i-1] * pattern(w - 3) % mod;
        }
        dp[0][i] %= mod;
        for (int j = 1; j < w - 1; ++j) {
            dp[j][i] = dp[j-1][i-1] * pattern(j - 2) * pattern(w - j - 2) % mod;
            dp[j][i] += dp[j][i-1] * pattern(j - 1) * pattern(w - j - 2) % mod;
            dp[j][i] += dp[j+1][i-1] * pattern(j - 1) * pattern(w - j - 3) % mod;
            dp[j][i] %= mod;
        }
        if (w > 1) {
            dp[w - 1][i] = dp[w - 2][i - 1] * pattern(w - 3) % mod;
            dp[w - 1][i] += dp[w - 1][i - 1] * pattern(w - 2) % mod;
            dp[w - 1][i] %= mod;
        }
    }
    cout << dp[k][h] << endl;
}
