#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 4/25 AC

int main() {
    string s;
    cin >> s;
    ll dp[100001][4] = {};
    ll n = (ll)s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            // s[i]を採用しない
            dp[i+1][0] = dp[i][0] % mod;
            dp[i+1][1] = dp[i][1] % mod;
            dp[i+1][2] = dp[i][2] % mod;
            dp[i+1][3] = dp[i][3] % mod;
            // s[i]を採用する
            if (s[i] == 'A') dp[i+1][1] += dp[i][0];
            if (s[i] == 'B') dp[i+1][2] += dp[i][1];
            if (s[i] == 'C') dp[i+1][3] += dp[i][2];
        } else {
            // s[i]を採用しない
            dp[i+1][0] = 3 * dp[i][0] % mod;
            dp[i+1][1] = 3 * dp[i][1] % mod;
            dp[i+1][2] = 3 * dp[i][2] % mod;
            dp[i+1][3] = 3 * dp[i][3] % mod;
            // s[i]を採用する
            dp[i+1][1] += dp[i][0];
            dp[i+1][2] += dp[i][1];
            dp[i+1][3] += dp[i][2];
        }
    }
    cout << dp[n][3] % mod << endl;
}