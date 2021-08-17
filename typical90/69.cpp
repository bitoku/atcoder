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
    ll n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k % mod << endl;
    } else if (n == 2) {
        cout << k * (k - 1) % mod << endl;
    } else {
        cout << k * (k - 1) % mod * mod_pow(k - 2, n - 2) % mod << endl;
    }
}