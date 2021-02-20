#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = 0;
    int cc = 0;
    for (int c = 1; c <= n; ++c) {
        ll dp[100][100][100] = {0};
        for (int i = 0; i < n; ++i) {
            int r = a[i] % c;
            dp[i][0][r] = max(dp[i][0][r], a[i]);
            for (int j = 0; j < c && j <= i; ++j) {
                for (int k = 0; k < c; ++k) {
                    int p = (k + r) % c;
                    if (j > 0 && dp[i-1][j-1][k] > 0) {
                        dp[i][j][p] = max(dp[i][j][p], dp[i-1][j-1][k] + a[i]);
                    }
                    dp[i][j][p] = max(dp[i][j][p], dp[i-1][j][p]);
                }
            }
        }
        if (dp[n-1][c-1][x % c] > result) {
            result = dp[n-1][c-1][x % c];
            cc = c;
        }
    }
    cout << (x - result) / cc << endl;
}
