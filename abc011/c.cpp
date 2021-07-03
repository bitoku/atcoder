#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    vector<vector<bool>> dp(301, vector<bool>(101));
    for (int i = 1; i <= 100; ++i) {
        if (a != 1 && b != 1 && c != 1) dp[1][i] = true;
        if (a != 2 && b != 2 && c != 2) dp[2][i] = true;
        if (a != 3 && b != 3 && c != 3) dp[3][i] = true;
    }
    for (int i = 4; i <= n; ++i) {
        if (i == a || i == b || i == c) continue;
        for (int j = 1; j <= 100; ++j) {
            dp[i][j] = dp[i-1][j-1] || dp[i-2][j-1] || dp[i-3][j-1];
        }
    }
    if (dp[n][100]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}