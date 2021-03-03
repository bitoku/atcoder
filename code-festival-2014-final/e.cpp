#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(2));
    vector<int> r(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        dp[i][0] = 1; // next up
        dp[i][1] = 1; // next down
        for (int j = 0; j < i; ++j) {
            if (dp[j][0] && r[j] < r[i]) {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            if (dp[j][1] && r[j] > r[i]) {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
    }
    if (max(dp[n-1][0], dp[n-1][1]) < 3) {
        cout << 0 << endl;
    } else {
        cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    }
}
