#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    multiset<ll> a, b, c;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        c.insert(x);
    }
    ll result = 0;
    for (auto x: a) {
        auto itb = b.upper_bound(x);
        if (itb == b.end()) break;
        auto itc = c.upper_bound(*itb);
        if (itc == c.end()) break;
        result++;
        b.erase(itb);
        c.erase(itc);
    }
    cout << result << endl;
}