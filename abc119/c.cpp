#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 07/29

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
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    vector<ll> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    ll lim = 1;
    for (int i = 0; i < n; ++i) {
        lim *= 4;
    }
    lim--;
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < lim; ++i) {
        ll temp = 0;
        ll cnt = 0;
        ll x[3] = {};
        for (ll j = 0; j < n; ++j) {
            ll k = i / mod_pow(4ll, j, LONG_LONG_MAX) % 4;
            if (k == 0) continue;
            x[k - 1] += l[j];
            cnt++;
        }
        if (x[0] == 0 || x[1] == 0 || x[2] == 0) continue;
        temp += abs(a[0] - x[0]) + abs(a[1] - x[1]) + abs(a[2] - x[2]);
        temp += (cnt - 3) * 10;
        result = min(result, temp);
    }
    cout << result << endl;
}