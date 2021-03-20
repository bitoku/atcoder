#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(3, vector<ll>(n+k));
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    for (int i = 0; i < k; ++i) {
        for (int j = i; j < n + k; j += k) {
            if (t[j] == 'r') {
                dp[0][j+k] = max({dp[1][j], dp[2][j]});
                dp[1][j+k] = max({dp[0][j], dp[2][j]});
                dp[2][j+k] = max({dp[0][j], dp[1][j]}) + p;
            }
            else if (t[j] == 's') {
                dp[0][j+k] = max({dp[1][j], dp[2][j]}) + r;
                dp[1][j+k] = max({dp[0][j], dp[2][j]});
                dp[2][j+k] = max({dp[0][j], dp[1][j]});
            }
            else if (t[j] == 'p') {
                dp[0][j+k] = max({dp[1][j], dp[2][j]});
                dp[1][j+k] = max({dp[0][j], dp[2][j]}) + s;
                dp[2][j+k] = max({dp[0][j], dp[1][j]});
            }
        }
    }
    ll result = 0;
    for (int i = n; i < n + k; ++i) {
        result += max({dp[0][i], dp[1][i], dp[2][i]});
    }
    cout << result << endl;
}
