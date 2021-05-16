#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    ll n;
    cin >> n;
    ll result = 0;
    for (ll i = 1; i <= n; ++i) {
        result += (mod_pow(i, 10ll, mod) - mod_pow(i-1, 10ll, mod)) * mod_pow(n / i, 10ll, mod) % mod;
        result %= mod;
    }
    cout << (result + mod) % mod << endl;
}