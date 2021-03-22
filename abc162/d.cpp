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
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (j + j - i >= n) continue;
            int k = j + j - i;
            if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) result--;
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
