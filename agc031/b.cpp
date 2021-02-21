#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n+1);
    vector<ll> color(200010);
    dp[0] = 1;
    int before = -1;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        c--;
        if (before != c) {
            dp[i+1] = (dp[i] + color[c]) % mod;
            color[c] = (color[c] + dp[i]) % mod;
        } else {
            dp[i+1] = dp[i];
        }
        before = c;
    }
    cout << dp[n] << endl;
}
