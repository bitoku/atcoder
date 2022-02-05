#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int d;
    string n;
    cin >> d;
    cin >> n;
    vector<vector<vector<ll>>> dp(n.size()+1, vector<vector<ll>>(d, vector<ll>(2)));
    dp[0][0][1] = 1;
    for (int i = 0; i < n.size(); ++i) {
        for (int j = 0; j < d; ++j) {
            for (int k = 0; k < 10; ++k) {
                dp[i+1][(j + k) % d][0] += dp[i][j][0];
                if (k < n[i] - '0') {
                    dp[i+1][(j + k) % d][0] += dp[i][j][1];
                }
                if (k == n[i] - '0') {
                    dp[i+1][(j + k) % d][1] += dp[i][j][1];
                }
                dp[i+1][(j + k) % d][0] %= mod;
                dp[i+1][(j + k) % d][1] %= mod;
            }
        }
    }
    cout << (dp[n.size()][0][0] + dp[n.size()][0][1] - 1 + mod) % mod << endl;
}