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
    ll n, l;
    cin >> n >> l;
    ll k;
    cin >> k;
    vector<ll> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = l;
    auto func = [&](ll x) {
        ll b = 0;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] - b >= x) {
                cnt++;
                b = a[i];
            }
        }
        if (cnt < k) return false;
        if (cnt > k) return true;
        if (l - b >= x) return true;
        return false;
    };
    cout << binsearch(l, 0, func) << endl;
}