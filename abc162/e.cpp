#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

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
    ll n, k;
    cin >> n >> k;
    ll result = 0;
    vector<ll> a(k+1);
    for (ll i = k; i >= 1; --i) {
        a[i] = mod_pow(k / i, n, mod);
        for (int j = 2; j * i <= k; ++j) {
            a[i] -= a[i * j];
            a[i] %= mod;
        }
        a[i] += mod;
        a[i] %= mod;
        result += i * a[i] % mod;
        result %= mod;
    }
    cout << result << endl;
}