#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        int dp[101][101];
        dp[0][0] = 0;
        for (int j = 1; j <= i; ++j) {
            dp[j][0] = 0;
        }
        for (int j = 1; j <= n - i; ++j) {
            dp[0][j] = 0;
        }
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < n - i; ++k) {
                if (s[j] == s[k + i]) {
                    dp[j+1][k+1] = dp[j][k] + 1;
                } else {
                    dp[j+1][k+1] = max(dp[j][k+1], dp[j+1][k]);
                }
            }
        }
        result = max(result, (ll)dp[i][n-i]);
    }
    cout << n - result * 2 << endl;
}
