#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}

int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    ll amari[2] = {};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        amari[a[i] % 2]++;
    }
    ll result = 0;
    if (p == 0 || amari[1] > 0) {
        result += mod_pow(2ll, amari[0]) * mod_pow(2ll, max(0ll, amari[1] - 1));
    }
    cout << result << endl;
}