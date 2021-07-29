#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    multiset<ll> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    set<ll> result;
    for (auto y: b) {
        ll x = a[0] ^ y;
        multiset<ll> c = b;
        c.erase(c.find(y));
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            ll z = a[i] ^ x;
            auto it = c.find(z);
            if (it == c.end()) {
                ok = false;
                break;
            }
            c.erase(it);
        }
        if (ok) result.insert(x);
    }
    cout << result.size() << endl;
    for (auto x: result) {
        cout << x << endl;
    }
}