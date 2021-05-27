#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll aisq = 0;
    for (int i = 0; i < n; ++i) {
        aisq += a[i] * a[i] % mod;
        aisq %= mod;
    }
    vector<ll> ajsum(n);
    for (ll i = 1; i < n; ++i) {
        ajsum[i] = ajsum[i-1];
        ajsum[i] += a[i] * mod_pow(2ll, i-1, mod) % mod;
        ajsum[i] %= mod;
    }
    ll result = 0;
    for (ll i = 0; i < n; ++i) {
        result += a[i] * mod_pow(mod_pow(2ll, i, mod), mod-2, mod) % mod * (ajsum[n-1] - ajsum[i] + mod) % mod;
        result %= mod;
    }
    cout << (result + aisq) % mod << endl;
}