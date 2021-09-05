#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 09/05

struct Point {
    ll x;
    ll y;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<Point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }
    vector<ll> d(1 << n);
    for (int i = 1; i < (1 << n); ++i) {
        int x = -1;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (x == -1) {
                    x = j;
                    d[i] = max(d[i], d[i - (1 << x)]);
                }
                d[i] = max(d[i], (v[x].x - v[j].x) * (v[x].x - v[j].x) + (v[x].y - v[j].y) * (v[x].y - v[j].y));
            }
        }
    }
    vector<vector<ll>> dp(1 << n, vector<ll>(k+1, LONG_LONG_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int l = j; l > 0; l = (l - 1) & j) {
                dp[j][i] = min(dp[j][i], max(dp[j-l][i-1], d[l]));
            }
        }
    }
    cout << dp[(1 << n) - 1][k] << endl;
}