#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll b;
        cin >> b;
        auto it = lower_bound(a.begin(), a.end(), b);
        ll result = LONG_LONG_MAX;
        if (it != a.end()) {
            result = abs(*it - b);
        }
        if (it != a.begin()) {
            result = min(result, abs(*(--it) - b));
        }
        cout << result << endl;
    }
}