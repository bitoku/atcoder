#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = (ll)1e9 + 7;

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
    vector<ll> one(61);
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        bitset<61> abit(a);
        for (int j = 0; j < 60; ++j) {
            if (abit[j]) one[j]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 61; ++i) {
        ll x = (n - one[i]) * one[i] % MOD;
        ans = (ans + (mod_pow(2ll, (ll)i, MOD) * x) % MOD) % MOD;
    }
    cout << ans << endl;
}
