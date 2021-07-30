#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 07/30

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll lim = 1ll << min(20ll, n);
    vector<ll> v;
    for (ll i = 0; i < lim; ++i) {
        ll temp = 0;
        for (int j = 0; j < min(20ll, n); ++j) {
            if (i & (1ll << j)) temp += a[j];
        }
        v.push_back(temp);
    }
    ll rest = 1ll << (n - min(20ll, n));
    set<ll> s;
    for (ll i = 0; i < rest; ++i) {
        ll temp = 0;
        for (int j = 0; j < (n - min(20ll, n)); ++j) {
            if (i & (1ll << j)) temp += a[min(20ll, n) + j];
        }
        s.insert(temp);
    }
    ll result = 0;
    for (auto x: v) {
        auto it = s.upper_bound(t - x);
        if (it == s.begin()) continue;
        result = max(result, x + *(--it));
    }
    cout << result << endl;
}