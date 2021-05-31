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
    vector<ll> plus;
    vector<ll> minus;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) minus.push_back(-a[i]);
        if (a[i] > 0) plus.push_back(a[i]);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    if (k <= minus.size() * plus.size()) {
        auto func = [&](ll x) {
            ll m = 0;
            for (auto t : plus) {
                auto it = upper_bound(minus.begin(), minus.end(), x / t);
                m += distance(it, minus.end());
            }
            if (m < k) return true;
            return false;
        };
        cout << -binsearch(0, LONG_LONG_MAX, func) << endl;
    } else if (k <= n * (n - 1) / 2 - plus.size() * (plus.size()-1) / 2 - minus.size() * (minus.size() - 1) / 2) {
        cout << 0 << endl;
    } else {
        ll target = n * (n - 1) / 2 - k;
        auto func = [&](ll x) {
            ll m = 0;
            for (auto it = plus.begin(); it != plus.end(); ++it) {
                ll t = *it;
                it++;
                auto itr = upper_bound(it, plus.end(), x / t);
                m += distance(itr, plus.end());
                it--;
            }
            for (auto it = minus.begin(); it != minus.end(); ++it) {
                ll t = *it;
                it++;
                auto itr = upper_bound(it, minus.end(), x / t);
                m += distance(itr, minus.end());
                it--;
            }
            if (m <= target) {
                return true;
            }
            return false;
        };
        cout << binsearch(0, LONG_LONG_MAX, func) << endl;
    }
}