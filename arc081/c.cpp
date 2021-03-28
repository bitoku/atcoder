#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        m[a]++;
    }
    vector<ll> rect;
    for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
        auto [x, k] = *rit;
        if (k < 2) continue;
        if (k >= 4 && rect.empty()) {
            cout << x * x << endl;
            return 0;
        }
        if (k >= 2) {
            rect.push_back(x);
        }
        if (rect.size() == 2) {
            cout << rect[0] * rect[1] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
