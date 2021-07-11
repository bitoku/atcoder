#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

// TODO: 07/11

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<vector<ll>>> dp(c + 1, vector<vector<ll>>(d + 1, vector<ll>(2)));
    dp[a][b][0] = 1;
    for (int i = a; i <= c; ++i) {
        for (int j = b; j <= d; ++j) {
            dp[i][j][0] = (dp[i][j][0] + i * dp[i][j-1][0] % mod + dp[i][j-1][1]) % mod;
            dp[i][j][1] = (dp[i][j][1] + j * dp[i-1][j][0] % mod + j * dp[i-1][j][1] % mod) % mod;
        }
    }
    cout << (dp[c][d][0] + dp[c][d][1]) % mod << endl;
}