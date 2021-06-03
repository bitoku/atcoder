#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    set<ll> r, g, b;
    for (int i = 0; i < 2 * n; ++i) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R') r.insert(a);
        if (c == 'G') g.insert(a);
        if (c == 'B') b.insert(a);
    }
    ll result;
    ll rg = LONG_LONG_MAX / 2;
    ll gb = LONG_LONG_MAX / 2;
    ll br = LONG_LONG_MAX / 2;
    for (auto x: r) {
        auto itg = g.lower_bound(x);
        if (itg != g.end()) rg = min(rg, *itg - x);
        auto itb = b.lower_bound(x);
        if (itb != b.end()) br = min(br, *itb - x);
    }
    for (auto x: b) {
        auto itr = r.lower_bound(x);
        if (itr != r.end()) br = min(br, *itr - x);
        auto itg = g.lower_bound(x);
        if (itg != g.end()) gb = min(gb, *itg - x);
    }
    for (auto x: g) {
        auto itb = b.lower_bound(x);
        if (itb != b.end()) gb = min(gb, *itb - x);
        auto itr = r.lower_bound(x);
        if (itr != r.end()) rg = min(rg, *itr - x);
    }
    if (r.size() % 2 != 0 && g.size() % 2 != 0) result = min(rg, br + gb);
    else if (g.size() % 2 != 0 && b.size() % 2 != 0) result = min(gb, rg + br);
    else if (b.size() % 2 != 0 && r.size() % 2 != 0) result = min(br, gb + rg);
    else {
        cout << 0 << endl;
        return 0;
    }
    cout << result << endl;
}