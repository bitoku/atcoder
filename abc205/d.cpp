#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    map<ll, ll> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]-i] = a[i] + 1;
    }
    for (int i = 0; i < q; ++i) {
        ll k;
        cin >> k;
        auto it = b.upper_bound(k);
        if (it != b.begin()) {
            it--;
            cout << k - it->first + it->second << endl;
        } else {
            cout << k << endl;
        }
    }
}