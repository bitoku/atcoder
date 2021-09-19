#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

// TODO: 09/19

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<vector<ll>>> dp(1 << 10, vector<vector<ll>>(10, vector<ll>(n + 1)));
    vector<vector<ll>> a(10);
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'A';
        vector<ll>& v = a[c];
        for (int j = 0; j < (1 << 10); ++j) {
            if (j == 0) {
                dp[1 << c][c][i+1]++;
            } else if (j & (1 << c)) {
                dp[j][c][i+1] += 2 * dp[j][c][i];
            } else {
                for (int k = 0; k < 10; ++k) {
                    if (!(j & (1 << k))) continue;
                    dp[j | (1 << c)][c][i+1] += dp[j][k][i];
                }
            }
        }
        for (int j = 0; j < (1 << 10); ++j) {
            for (int k = 0; k < 10; ++k) {
                if (k == c) continue;
                dp[j][k][i+1] = dp[j][k][i];
            }
        }
        for (int j = 0; j < (1 << 10); ++j) {
            dp[j][c][i+1] %= mod;
        }
    }
    ll result = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < (1 << 10); ++j) {
            result += dp[j][i][n];
        }
        result %= mod;
    }
    cout << (result + mod) % mod << endl;
}