#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n+1));
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> sum(n+1);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + a[i];
    }
    vector<vector<ll>> x(n+1, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            x[i+1][sum[j] % (i + 1)] += dp[j][i];
            x[i+1][sum[j] % (i + 1)] %= mod;
        }
        if (i == 0) continue;
        for (int j = 0; j < n; ++j) {
            dp[j][i] = x[i][sum[j] % i];
        }
    }
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        result += dp[n-1][i];
        result %= mod;
    }
    cout << result << endl;
}