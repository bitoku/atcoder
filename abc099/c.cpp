#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    set<ll, greater<>> x;
    vector<int> dp(n+1);
    x.insert(1);
    for (ll i = 1; mod_pow(6ll, i, LONG_LONG_MAX) <= n; ++i) {
        x.insert(mod_pow(6ll, i, LONG_LONG_MAX));
    }
    for (ll i = 1; mod_pow(9ll, i, LONG_LONG_MAX) <= n; ++i) {
        x.insert(mod_pow(9ll, i, LONG_LONG_MAX));
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = INT_MAX;
        for (const auto y: x) {
            if (i < y) continue;
            dp[i] = min(dp[i], dp[i-y] + 1);
        }
    }
    cout << dp[n] << endl;
}
