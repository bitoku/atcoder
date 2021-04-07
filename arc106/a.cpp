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
    ll threelim = 0;
    ll three = 1;
    while (three <= LONG_LONG_MAX / 3) {
        three *= 3;
        threelim++;
    }
    ll fivelim = 0;
    ll five = 1;
    while (five <= LONG_LONG_MAX / 5) {
        five *= 5;
        fivelim++;
    }
    map<ll, pair<ll, ll>> m;
    for (ll i = 1; i <= threelim; ++i) {
        for (ll j = 1; j <= fivelim && mod_pow(5ll, j, LONG_LONG_MAX) <= LONG_LONG_MAX - mod_pow(3ll, i, LONG_LONG_MAX); ++j) {
            m[mod_pow(5ll, j, LONG_LONG_MAX) + mod_pow(3ll, i, LONG_LONG_MAX)] = make_pair(i, j);
        }
    }
    ll n;
    cin >> n;
    if (m.find(n) != m.end()) {
        cout << m[n].first << ' ' << m[n].second << endl;
    } else {
        cout << -1 << endl;
    }
}
