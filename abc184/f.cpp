#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<ll> b;
    set<ll> c;
    b.insert(0);
    c.insert(0);
    for (int i = 0; i < n; ++i) {
        set<ll> &d = i % 2 == 0 ? b : c;
        vector<ll> next;
        for (const auto y : d) {
            if (y + a[i] > t) continue;
            next.push_back(y + a[i]);
        }
        for (const auto y : next) {
            d.insert(y);
        }
    }
    ll result = 0;
    for (const auto x : b) {
        auto it = c.upper_bound(t - x);
        result = max(result, *(--it) + x);
    }
    cout << result << endl;
}
