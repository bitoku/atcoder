#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> m(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j <= n; ++j) {
            m[j][i] = a[i] % j;
        }
    }
    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            m[j][i] += m[j][i-1];
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i - 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j];
        }
    }
}