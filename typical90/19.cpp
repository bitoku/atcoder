#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/04

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> dp(2 * n + 1, vector<ll>(2 * n + 1, INT_MAX));
    vector<ll> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= 2 * n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        dp[i][i+2] = abs(a[i+1] - a[i]);
    }
    for (int i = 4; i <= 2 * n; i += 2) {
        for (int j = 0; j < 2 * n - i + 1; ++j) {
            for (int k = 0; k < i; ++k) {
                for (int l = k + 1; l < i; l += 2) {
                    dp[j][j+i] = min(dp[j][j+i],
                                     dp[j][j+k] +
                                     dp[j+k+1][j+l] +
                                     dp[j+l+1][j+i] +
                                     abs(a[j + k] - a[j + l]));
                }
            }
        }
    }
    cout << dp[0][2*n] << endl;
}