#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll l, r;
    cin >> l >> r;
    ll m = 2019;
    if (r - l + 1 >= m) {
        cout << 0 << endl;
        return 0;
    }
    ll result = LONG_LONG_MAX;
    for (ll i = l; i <= r; ++i) {
        for (ll j = i + 1; j <= r; ++j) {
            ll ii = i % m;
            ll jj = j % m;
            result = min(result, ii * jj % m);
        }
    }
    cout << result << endl;
}
