#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    // ngは常に条件を満たさない, okは常に条件を満たす
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
    sort(a.begin(), a.end(), greater<>());
    sort(f.begin(), f.end());
    auto func = [a, f, k, n](ll x) {
        ll temp = k;
        for (int i = 0; i < n; ++i) {
            temp -= max(a[i] - x / f[i], 0ll);
            if (temp < 0) return false;
        }
        return true;
    };
    cout << binsearch(-1, 1ll << 40, func) << endl;
}

