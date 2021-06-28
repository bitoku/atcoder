#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 6/28

int main() {
    ll n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<ll> dp(n+1);
    vector<ll> color(200001, -1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (color[c[i]] == i - 1 || color[c[i]] == -1) {
            dp[i+1] = dp[i] % mod;
        } else {
            dp[i+1] = (dp[i] + dp[color[c[i]] + 1]) % mod;
        }
        color[c[i]] = i;
    }
    cout << dp[n] << endl;
}