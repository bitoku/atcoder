#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> dp(8, vector<ll>(n+1));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            dp[1][i+1] += dp[0][i];
        }
        if (s[i] == 't') {
            dp[2][i+1] += dp[1][i];
        }
        if (s[i] == 'c') {
            dp[3][i+1] += dp[2][i];
        }
        if (s[i] == 'o') {
            dp[4][i+1] += dp[3][i];
        }
        if (s[i] == 'd') {
            dp[5][i+1] += dp[4][i];
        }
        if (s[i] == 'e') {
            dp[6][i+1] += dp[5][i];
        }
        if (s[i] == 'r') {
            dp[7][i+1] += dp[6][i];
        }
        for (int j = 0; j < 8; ++j) {
            dp[j][i+1] += dp[j][i];
            dp[j][i+1] %= mod;
        }
    }
    cout << dp[7][n] << endl;
}