#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll cpb[40] = {}; // count per bit
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; (1ll << j) <= a[i]; j++) {
            if (a[i] & (1ll << j)) cpb[j]++;
        }
    }
    ll dp[41][2] = {};
    for (ll i = 0; i < 40; ++i) {
        dp[i+1][1] = (max(cpb[i], n - cpb[i]) << i) + dp[i][1];
        if (k & (1ll << i)) {
            dp[i+1][0] = max((cpb[i] << i) + dp[i][1], ((n - cpb[i]) << i) + dp[i][0]);
        } else {
            dp[i+1][0] = (cpb[i] << i) + dp[i][0];
        }
    }
    cout << dp[40][0] << endl;
}
