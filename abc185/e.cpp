#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                dp[i+1][j+1] = min({dp[i][j+1] + 1, dp[i+1][j] + 1, dp[i][j]});
            } else {
                dp[i+1][j+1] = min({dp[i][j+1] + 1, dp[i+1][j] + 1, dp[i][j] + 1});
            }
        }
    }
    cout << dp[n][m] << endl;
}
