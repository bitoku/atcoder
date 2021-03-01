#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll dp[1 << 12];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 1 << n; ++i) {
        dp[i] = LONG_LONG_MAX / 3;
    }
    dp[0] = 0;
    vector<pair<ll, int>> keys(m);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        int x = 0;
        for (int j = 0; j < b; ++j) {
            int c;
            cin >> c;
            c--;
            x |= 1 << c;
        }
        keys[i] = make_pair(a, x);
        dp[x] = min(dp[x], a);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 1 << n; ++j) {
            dp[j | keys[i].second] = min(dp[j] + keys[i].first, dp[j | keys[i].second]);
        }
    }
    if (dp[(1 << n) - 1] == LONG_LONG_MAX / 3) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << n) - 1] << endl;
    }
}
