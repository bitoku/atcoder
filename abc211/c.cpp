#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    vector<vector<ll>> dp(9, vector<ll>(s.size()+1));
    for (int i = 0; i <= s.size(); ++i) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'c') {
            dp[1][i+1] += dp[0][i];
        } else if (s[i] == 'h') {
            dp[2][i+1] += dp[1][i];
        } else if (s[i] == 'o') {
            dp[3][i+1] += dp[2][i];
        } else if (s[i] == 'k') {
            dp[4][i+1] += dp[3][i];
        } else if (s[i] == 'u') {
            dp[5][i+1] += dp[4][i];
        } else if (s[i] == 'd') {
            dp[6][i+1] += dp[5][i];
        } else if (s[i] == 'a') {
            dp[7][i+1] += dp[6][i];
        } else if (s[i] == 'i') {
            dp[8][i+1] += dp[7][i];
        }
        for (int j = 1; j <= 8; ++j) {
            dp[j][i+1] += dp[j][i];
            dp[j][i+1] %= mod;
        }
    }
    cout << dp[8][s.size()] << endl;
}