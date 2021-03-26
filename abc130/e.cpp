#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    vector<vector<ll>> sum(n+1, vector<ll>(m+1));
    vector<ll> s(n);
    vector<ll> t(m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = (sum[i][j] + 1) % mod;
            } else {
                dp[i+1][j+1] = 0;
            }
            sum[i+1][j+1] = (sum[i+1][j] + sum[i][j+1] - sum[i][j] + dp[i+1][j+1] + mod) % mod;
        }
    }
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            result += dp[i][j];
            result %= mod;
        }
    }
    cout << result + 1 << endl;
}
