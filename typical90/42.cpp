#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll k;
    cin >> k;
    if (k % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dp(k+1);
    for (int i = 1; i < 10; ++i) {
        dp[i] = 1;
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 1; j < 10; ++j) {
            if (i - j < 0) break;
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    cout << dp[k] << endl;
}