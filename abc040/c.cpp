#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> dp(n, LONG_LONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
        if (i + 2 >= n) continue;
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
    }
    cout << dp[n-1] << endl;
}