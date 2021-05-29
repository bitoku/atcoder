#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i] *= m;
    }
    auto func = [&](ll x) {
        vector<ll> l(k);
        vector<ll> r(k);
        ll sl = 0;
        ll sr = 0;
        for (int i = 0; i < k; ++i) {
            l[i] = (a[i] - x + n - 1) / n;
            r[i] = (a[i] + x) / n;
            sl += l[i];
            sr += r[i];
        }
        if (sl <= m && m <= sr) return true;
        return false;
    };
    ll x = binsearch(0, LONG_LONG_MAX, func);
    vector<ll> b(k);
    vector<ll> r(k);
    ll sb = 0;
    for (int i = 0; i < k; ++i) {
        b[i] = (a[i] - x + n - 1) / n;
        r[i] = (a[i] + x) / n;
        sb += b[i];
    }
    for (int i = 0; i < k; ++i) {
        ll diff = min(m - sb, r[i] - b[i]);
        b[i] += diff;
        sb += diff;
    }
    cout << b[0];
    for (int i = 1; i < k; ++i) {
        cout << ' ' << b[i];
    }
    cout << endl;
}