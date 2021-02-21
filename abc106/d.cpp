#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m, Q;
    cin >> n >> m >> Q;
    ll dp[501][501] = {0};
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        dp[l][r]++;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] += dp[i][j-1];
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = n-1; i >= 0; --i) {
            dp[i][j] += dp[i+1][j];
        }
    }
    for (int i = 0; i < Q; ++i) {
        int p, q;
        cin >> p >> q;
        cout << dp[p][q] << endl;
    }
}
