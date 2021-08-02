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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());
    sort(a.begin(), a.end());
    auto func = [&](ll x) {
        ll temp = 0;
        for (int i = 0; i < n; ++i) {
            ll t = x / f[i];
            if (a[n-i-1] > t) {
                temp += a[n-i-1] - t;
            }
            if (temp > k) {
                return false;
            }
        }
        return true;
    };
    cout << binsearch(-1, 1e13, func) << endl;
}