#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve

int main() {
    int n, q;
    cin >> n;
    ll sum = 0;
    map<ll, ll> m;
    m[LONG_LONG_MAX] = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll a, t;
        cin >> a >> t;
        if (t == 1) {
            sum += a;
        } else if (t == 2) {
            a -= sum;
            auto it = m.upper_bound(a);
            m.erase(m.begin(), it);
            m[a] = a;
        } else {
            a -= sum;
            auto it = m.lower_bound(a);
            ll temp = (*it).second;
            m.erase(it, m.end());
            m[LONG_LONG_MAX] = a;
            m[a] = temp;
        }
    }
//    for (const auto& [a, b]: m) {
//        cout << a << ' ' << b << endl;
//    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        auto it = m.lower_bound(x);
        ll y = (*it).second;
        if (y == LONG_LONG_MAX) {
            cout << x + sum << endl;
        } else {
            cout << y + sum << endl;
        }
    }
}
