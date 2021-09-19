#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> dp(1 << 10, vector<ll>(n + 1));
    vector<vector<ll>> dps(1 << 10, vector<ll>(n + 1));
    vector<vector<ll>> a(10);
    for (int i = 0; i < (1 << 10); ++i) {
        dp[i][0] = 1;
        dps[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'A';
        vector<ll>& v = a[c];
        for (int j = 0; j < (1 << 10); ++j) {
            if (j & (1 << c)) continue;
            dp[j | (1 << c)][i+1] = dps[j][i];
        }
        for (auto x: v) {
            for (int j = 0; j < (1 << 10); ++j) {
                if (!(j & (1 << c))) continue;
                dp[j][i+1] += dp[j][x];
                dp[j][i+1] %= mod;
            }
        }
        v.push_back(i+1);
        for (int j = 0; j < (1 << 10); ++j) {
            dps[j][i+1] = dp[j][i+1] + dps[j][i];
            dps[j][i+1] %= mod;
        }
    }
    int bit = 0;
    for (int i = 0; i < n; ++i) {
        bit |= (1 << (s[i] - 'A'));
    }
    cout << (dps[bit][n] - 1 + mod) % mod << endl;
}