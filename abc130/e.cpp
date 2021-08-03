#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 08/03

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> s(n), t(m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
            if (s[i] != t[j]) {
                dp[i + 1][j + 1] -= dp[i][j];
            }
            dp[i+1][j+1] = (dp[i+1][j+1] + mod) % mod;
        }
    }
    cout << dp[n][m] << endl;
}