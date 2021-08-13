#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, s;
    cin >> n >> s;
    vector<vector<int>> dp(n+1, vector<int>(s+1));
    vector<ll> a(n), b(n);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        for (int j = 0; j <= s; ++j) {
            if (dp[i][j] == 0) continue;
            if (j + a[i] <= s) dp[i+1][j+a[i]] = 1;
            if (j + b[i] <= s) dp[i+1][j+b[i]] = 2;
        }
    }
    ll before = s;
    string result;
    if (dp[n][s] == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = n; i > 0; --i) {
        if (dp[i][before] == 1) {
            result.push_back('A');
            before -= a[i-1];
        }
        else if (dp[i][before] == 2) {
            result.push_back('B');
            before -= b[i-1];
        }
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}