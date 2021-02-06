#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(k);
    vector<int> r(k);
    for (int i = 0; i < k; ++i) {
        cin >> l[i] >> r[i];
        l[i];
        r[i];
    }
    vector<int> dp(n+1);
    vector<int> sdp(n+1);
    dp[1] = 1;
    sdp[1] = dp[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 0; j < k; ++j) {
            ll left = 0;
            ll right = 0;
            if (i - l[j] >= 0) {
                left = sdp[i - l[j]];
            }
            if (i - r[j] - 1 >= 0) {
                right = sdp[i - r[j] - 1];
            }
            dp[i] = (dp[i] + left - right + mod) % mod;
        }
        sdp[i] = (sdp[i-1] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
}