#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/01

int main() {
    ll k;
    cin >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    if (a[k-1] != 2) {
        cout << -1 << endl;
        return 0;
    }
    reverse(a.begin(), a.end());
    ll l = 2, r = 2;
    for (int i = 0; i < k; ++i) {
        ll x = (l + a[i] - 1) / a[i] * a[i];
        ll y = (r / a[i]) * a[i];
        if (x < l || r < x || y < l || r < y) {
            cout << -1 << endl;
            return 0;
        }
        l = x;
        r = y + a[i] - 1;
    }
    cout << l << ' ' << r << endl;
}