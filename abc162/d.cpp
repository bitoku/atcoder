#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll dp[8][4001];

ll solve(ll n, string& s) {
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            dp[j][i+1] = dp[j][i];
        }
        if (s[i] == 'R') {
            dp[0b001][i+1] += dp[0b000][i];
            dp[0b011][i+1] += dp[0b010][i];
            dp[0b101][i+1] += dp[0b100][i];
            dp[0b111][i+1] += dp[0b110][i];
        } else if (s[i] == 'G') {
            dp[0b010][i+1] += dp[0b000][i];
            dp[0b011][i+1] += dp[0b001][i];
            dp[0b110][i+1] += dp[0b100][i];
            dp[0b111][i+1] += dp[0b101][i];
        } else {
            dp[0b100][i+1] += dp[0b000][i];
            dp[0b101][i+1] += dp[0b001][i];
            dp[0b110][i+1] += dp[0b010][i];
            dp[0b111][i+1] += dp[0b011][i];
        }
    }
    ll result = dp[7][n];
    for (int j = 1; j <= n / 2; ++j) {
        for (int i = 0; i < n - 2 * j; ++i) {
            if (s[i] != s[i + j] && s[i + j] != s[i + 2 * j] && s[i] != s[i + 2 * j]) result--;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << endl;
}
