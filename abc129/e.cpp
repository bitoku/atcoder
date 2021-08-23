#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/23

int main() {
    string l;
    cin >> l;
    reverse(l.begin(), l.end());
    vector<vector<ll>> dp(2, vector<ll>(l.size() + 1));
    dp[0][0] = 1;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] == '0') {
            dp[0][i+1] = dp[0][i] % mod;
            dp[1][i+1] = (2 * dp[0][i] + 3 * dp[1][i]) % mod;
        } else {
            dp[0][i+1] = (3 * dp[0][i] + dp[1][i]) % mod;
            dp[1][i+1] = 2 * dp[1][i] % mod;
        }
    }
    cout << dp[0][l.size()] << endl;
}