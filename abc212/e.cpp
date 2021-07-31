#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> broken(n);
    vector<vector<ll>> dp(k, vector<ll>(n));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        broken[u].push_back(v);
        broken[v].push_back(u);
    }
    dp[0][0] = 1;
    for (int i = 0; i < k - 1; ++i) {
        ll sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += dp[i][j];
            sum %= mod;
        }
        for (int j = 0; j < n; ++j) {
            ll temp = sum - dp[i][j];
            for (auto x: broken[j]) {
                temp -= dp[i][x];
                temp %= mod;
            }
            dp[i+1][j] = (temp % mod + mod) % mod;
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result += dp[k-1][i];
        result %= mod;
    }
    result -= dp[k-1][0];
    for (auto x: broken[0]) {
        result -= dp[k-1][x];
        result %= mod;
    }
    cout << (result % mod + mod) % mod << endl;
}