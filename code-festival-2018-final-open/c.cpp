#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> mm;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        mm[a] = b;
    }
    ll m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll t;
        cin >> t;
        auto it = mm.lower_bound(t);
        if (it == mm.end()) {
            --it;
            cout << it->second + t - it->first << endl;
        } else if (it->first == t) {
            cout << it->second << endl;
        } else {
            ll result = it-> second;
            if (it != mm.begin()) {
                --it;
                result = min(result, it->second + t - it->first);
            }
            cout << result << endl;
        }
    }
}
