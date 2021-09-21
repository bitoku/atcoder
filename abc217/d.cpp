#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    set<ll> s;
    ll l;
    cin >> l;
    s.insert(l);
    s.insert(0);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int c;
        ll x;
        cin >> c >> x;
        if (c == 1) {
            s.insert(x);
        } else {
            auto it = s.upper_bound(x);
            cout << *it - *(--it) << endl;
        }
    }
}