#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/30

int main() {
    string n;
    cin >> n;
    vector<vector<ll>> dp(2, vector<ll>(n.size()+1));
    dp[1][0] = 1;
    for (int i = 0; i < n.size(); ++i) {
        ll k = n[i] - '0';
        dp[0][i+1] = min(dp[0][i] + k, dp[1][i] + 10 - k);
        dp[1][i+1] = min(dp[0][i] + k + 1, dp[1][i] + 9 - k);
    }
    cout << dp[0][n.size()] << endl;
}