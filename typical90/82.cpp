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

ll count(ll x) {
    ll result = 0;
    ll t = x % mod;
    int d = 0;
    while (x > 0) {
        x /= 10;
        d++;
    }
    ll ten = 1;
    for (int i = 1; i <= d; ++i) {
        result += t % mod * (t + 1) % mod * mod_pow(2ll, mod-2) % mod;
        result -= (ten - 1) % mod * ten % mod * mod_pow(2ll, mod-2) % mod;
        result %= mod;
        ten *= 10;
        ten %= mod;
    }
    return (result + mod) % mod;
}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << (count(r) - count(l-1) + mod) % mod << endl;
}