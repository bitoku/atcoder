#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/02

int main() {
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> work(n);
    ll mxd = 0;
    for (int i = 0; i < n; ++i) {
        ll c, d, s;
        cin >> d >> c >> s;
        work[i] = make_tuple(d, c, s);
        mxd = max(mxd, d);
    }
    sort(work.begin(), work.end());
    vector<vector<ll>> dp(n+1, vector<ll>(mxd+1));
    for (int i = 0; i < n; ++i) {
        auto [d, c, s] = work[i];
        for (int j = 0; j <= mxd; ++j) {
            if (j < c || d < j) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-c] + s);
            }
        }
    }
    ll result = 0;
    for (int i = 0; i <= mxd; ++i) {
        result = max(dp[n][i], result);
    }
    cout << result << endl;
}